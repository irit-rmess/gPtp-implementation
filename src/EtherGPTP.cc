//
// @authors: Enkhtuvshin Janchivnyambuu
//           Henning Puttnies
//           Peter Danielis
//           University of Rostock, Germany
//
// Edit by : Quentin Bailleul (IRT Saint Exupéry)
//      Copyright (c) 2022 IRT Saint Exupéry

#include "EtherGPTP.h"
#include "tableGPTP.h"
#include "Clock.h"
#include "gPtp.h"
#include "gPtpPacket_m.h"
#include <omnetpp.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <list>
#include <utility>

#include "inet/linklayer/ethernet/EtherMACBase.h"
#include "inet/linklayer/ethernet/EtherFrame_m.h"
#include "inet/linklayer/common/MACAddress.h"
#include "inet/linklayer/base/MACBase.h"

Define_Module(EtherGPTP);

using namespace omnetpp;

EtherGPTP::EtherGPTP()
    : selfMsgSync(NULL), selfMsgDelayReq(NULL), selfMsgDelayResp(NULL), selfMsgFollowUp(NULL)
{
}

/*Inialize the EtherGPTP object*/
void EtherGPTP::initialize(int stage)
{
    cModule* gPtpNode=getParentModule()->getParentModule();
    if(gPtpNode->getSubmodule("tableGPTP")!=nullptr)
    {
        tableGptp = check_and_cast<TableGPTP *>(gPtpNode->getSubmodule("tableGPTP"));
    }
    if(gPtpNode->getSubmodule("clock")!=nullptr)
     {
        clockGptp = check_and_cast<Clock *>(gPtpNode->getSubmodule("clock"));
     }

    stepCounter = 0;
    peerDelay= tableGptp->getPeerDelay();
    portType = par("portType");
    nodeType = gPtpNode->par("gPtpNodeType");
    syncInterval = par("syncInterval");

    edge100BaseT = par("edge100BaseT");
    if (edge100BaseT == -1){
        edge100BaseT = rand() % 5; //Select a random edge if the edge100BaseT == -1
    }

    neighborRateRatio = 1;
    sentTimeSyncSync = 0;

    /* following parameters are used to schedule follow_up and pdelay_resp messages.
     * These numbers must be enough large to prevent creating queue in MAC layer.
     * It means it should be large than transmission time of message sent before */
    PDelayRespInterval = 0.000008;
    FollowUpInterval = 0.000007;

    /* Only grandmaster in the domain can initialize the synchronization message periodically
     * so below condition checks whether it is grandmaster and then schedule first sync message */
    if(portType == MASTER_PORT && nodeType == MASTER_NODE)
    {
        // Schedule Sync message to be sent
        if (NULL == selfMsgSync)
            selfMsgSync = new cMessage("selfMsgSync");

        scheduleSync = getRandDouble(syncInterval.dbl(),0.05);  // Schedule the first Sync message at a random time between 0.05s and 0.125s
        tableGptp->setOriginTimestamp(scheduleSync);
        scheduleAt(scheduleSync, selfMsgSync);
    }
    else if(portType == SLAVE_PORT)
    {
        vLocalTime.setName("Clock local");
        vMasterTime.setName("Clock master");
        vTimeDifference.setName("Clock difference to neighbor");
        vNeighborRateRatio.setName("Neighbor rate ratio");
        vPeerDelay.setName("Peer delay");
        vTimeDifferenceGMafterSync.setName("Clock difference to GM after Sync");
        vTimeDifferenceGMbeforeSync.setName("Clock difference to GM before Sync");

        requestMsg = new cMessage("requestToSendSync");

        // Schedule Pdelay_Req message is sent by slave port
        // without depending on node type which is grandmaster or bridge
        if (NULL == selfMsgDelayReq)
            selfMsgDelayReq = new cMessage("selfMsgPdelay");
        pdelayInterval = par("pdelayInterval");

        schedulePdelay = pdelayInterval;
        scheduleAt(schedulePdelay, selfMsgDelayReq);
    }
}
/* Return a random double between LOW and HIGH */
double EtherGPTP::getRandDouble(double HIGH, double LOW){
    double randDouble = LOW + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HIGH-LOW)));
    return randDouble;
}

/* Handle message */
void EtherGPTP::handleMessage(cMessage *msg)
{
    tableGptp->setReceivedTimeAtHandleMessage(simTime());

    if(portType == MASTER_PORT)
    {
        masterPort(msg);
    }
    else if(portType == SLAVE_PORT)
    {
        slavePort(msg);
    }
    else
    {
        // Forward message to upperLayerOut gate since packet is not gPtp
        if(msg->arrivedOn("lowerLayerIn"))
        {
            EV_INFO << "EtherGPTP: Received " << msg << " from LOWER LAYER." << endl;
            send(msg, "upperLayerOut");
        }
        else if (msg->arrivedOn("gptpLayerIn")){
            //DO nothing
        }
        else
        {
            EV_INFO << "EtherGPTP: Received " << msg << " from UPPER LAYER." << endl;
           send(msg, "lowerLayerOut");
        }
    }
}

/* Return the PLL edge */
int EtherGPTP::getEdge100BaseT(){
    return edge100BaseT;
}

/*********************************/
/* Master port related functions */
/*********************************/

void EtherGPTP::masterPort(cMessage *msg)
{
    if (msg->isSelfMessage())
    {
        if(selfMsgSync == msg)
        {
            sendSync(clockGptp->getCurrentTime());
            /* Schedule next Sync message at next sync interval
             * Grand master always works at simulation time */
            scheduleSync = simTime() + syncInterval;
            scheduleAt(scheduleSync, msg);
        }
        else if(selfMsgFollowUp == msg)
        {
            sendFollowUp();
        }
        else if(selfMsgDelayResp == msg)
        {
            sendPdelayResp();
        }
    }
    else if (msg->arrivedOn("gptpLayerIn"))
    {
        // Only sync message is sent if its node is bridge
        if(nodeType == BRIDGE_NODE)
        {
            sendSync(clockGptp->getCurrentTime());
        }
        delete msg;
    }
    else if(msg->arrivedOn("lowerLayerIn"))
    {
        if (inet::EthernetIIFrame* etherFrame = dynamic_cast<inet::EthernetIIFrame*>(msg))
        {
            if(msg->getKind() == PDELAY_REQ)
            {
                gPtp_PdelayReq* gptp = dynamic_cast<gPtp_PdelayReq*>(etherFrame->decapsulate());
                processPdelayReq(gptp);
            }
            else
            {
                // Forward message to upperLayerOut gate since packet is not gPtp
                send(msg, "upperLayerOut");
            }
        }
        else
        {
            // Forward message to upperLayerOut gate since packet is not gPtp
            send(msg, "upperLayerOut");
        }
    }
    else if (msg->arrivedOn("upperLayerIn"))
    {
        // Forward message to lowerLayerOut gate because the message from upper layer doesn't need to be touched
        // and we are interested in only message from lowerLayerIn
        send(msg, "lowerLayerOut");
    }
}

void EtherGPTP::sendSync(SimTime value)
{
    // Create EtherFrame to be used to encapsulate gPtpPacket because lower layer MAC only supports EtherFrame
    inet::EthernetIIFrame* frame=new inet::EthernetIIFrame("gPtpPacket");
    frame->setDest(inet::MACAddress::BROADCAST_ADDRESS);
    frame->setEtherType(inet::ETHERTYPE_IPv4);  // So far INET doesn't support gPTP (etherType = 0x88f7)
    frame->setKind(SYNC);
    gPtp_Sync* gptp = gPtp::newSyncPacket();

    //Normally, timestamps are taken when the first bit of the message is received. In order not to make any modification to INET, it is taken at the end of the reception. It is therefore necessary to take into account the transmission time.
    double bits = (MAC_HEADER + SYNC_PACKET_SIZE + CRC_CHECKSUM + 2)*8;
    SimTime packetTransmissionTime = (SimTime)bits/100000000 + clockGptp->getCalculatedDrift((SimTime)bits/100000000);

    /* OriginTimestamp always get Sync departure time from grand master */
    if (nodeType == MASTER_NODE)
    {
        sentTimeSyncSync = value + packetTransmissionTime;

        tableGptp->setOriginTimestamp(sentTimeSyncSync);

        gptp->setOriginTimestamp(sentTimeSyncSync);
        gptp->setSentTime(sentTimeSyncSync);
    }
    else if(nodeType == BRIDGE_NODE)
    {
        gptp->setOriginTimestamp(tableGptp->getOriginTimestamp());
        sentTimeSyncSync = clockGptp->getCurrentTime() + packetTransmissionTime;
        gptp->setSentTime(sentTimeSyncSync);
    }

    frame->encapsulate(gptp);

    send(frame,"lowerLayerOut");

    if (NULL == selfMsgFollowUp)
        selfMsgFollowUp = new cMessage("selfMsgFollowUp");
    scheduleAt(simTime() + FollowUpInterval, selfMsgFollowUp);
}

void EtherGPTP::sendFollowUp()
{
    // Create EtherFrame to be used to encapsulate gPtpPacket because lower layer MAC only supports EtherFrame
    inet::EthernetIIFrame* frame=new inet::EthernetIIFrame("gPtpPacket");
    frame->setDest(inet::MACAddress::BROADCAST_ADDRESS);
    frame->setEtherType(inet::ETHERTYPE_IPv4);  // So far INET doesn't support gPTP (etherType = 0x88f7)
    frame->setKind(FOLLOW_UP);

    gPtp_FollowUp* gptp = gPtp::newFollowUpPacket();
    gptp->setSentTime(clockGptp->getCurrentTime());
    gptp->setPreciseOriginTimestamp(tableGptp->getOriginTimestamp());

    if (nodeType == MASTER_NODE){
        gptp->setCorrectionField(0);
        gptp->setRateRatio(1);
    }
    else if (nodeType == BRIDGE_NODE){
        /**************** Correction field calculation *****************************************************************************
         * It is calculated by adding peer delay, residence time and packet transmission time                                      *
         * correctionField(i)=correctionField(i-1)+peerDelay*rateRatio+(timeReceivedSync-timeSentSync)*rateRatio*neighborRateRatio *
         ***************************************************************************************************************************/
        gptp->setCorrectionField(tableGptp->getCorrectionField() + tableGptp->getRateRatio().dbl()*tableGptp->getPeerDelay() + tableGptp->getRateRatio().dbl()*tableGptp->getNeighborRateRatio().dbl()*(sentTimeSyncSync - tableGptp->getReceivedTimeSync()));
        gptp->setRateRatio((tableGptp->getRateRatio()*tableGptp->getNeighborRateRatio().dbl()).dbl());

        EV_INFO << "Previous correctionField        " << tableGptp->getCorrectionField() << endl;
        EV_INFO << "Peer delay                      " << tableGptp->getPeerDelay() << endl;
        EV_INFO << "Residence Time                  " << (SimTime)(sentTimeSyncSync - tableGptp->getReceivedTimeSync()) << endl;
        EV_INFO << "New correctionField             " << gptp->getCorrectionField() << endl;
    }
    gptp->setNeighborRateRatio(tableGptp->getNeighborRateRatio());
    frame->encapsulate(gptp);

    send(frame, "lowerLayerOut");
}

void EtherGPTP::processPdelayReq(gPtp_PdelayReq* gptp){

    receivedTimeResponder = clockGptp->getCurrentTime();
    if (NULL == selfMsgDelayResp)
        selfMsgDelayResp = new cMessage("selfMsgPdelayResp");

    schedulePdelayResp = simTime() + (SimTime)PDelayRespInterval;
    scheduleAt(schedulePdelayResp, selfMsgDelayResp);
}

void EtherGPTP::sendPdelayResp()
{
    // Create EtherFrame to be used to encapsulate gPtpPacket because lower layer MAC only supports EtherFrame
    inet::EthernetIIFrame* frame=new inet::EthernetIIFrame("gPtpPacket");
    frame->setDest(inet::MACAddress::BROADCAST_ADDRESS);
    frame->setEtherType(inet::ETHERTYPE_IPv4);  // So far INET doesn't support gPTP (etherType = 0x88f7)
    frame->setKind(PDELAY_RESP);

    gPtp_PdelayResp* gptp = gPtp::newDelayRespPacket();

    //Normally, timestamps are taken when the first bit of the message is received. In order not to make any modification to INET, it is taken at the end of the reception. It is therefore necessary to take into account the transmission time.
    double bits = (MAC_HEADER + PDELAY_RESP_PACKET_SIZE + CRC_CHECKSUM)*8;
    SimTime packetTransmissionTime = (SimTime)bits/100000000 + clockGptp->getCalculatedDrift((SimTime)bits/100000000);
    gptp->setSentTime(clockGptp->getCurrentTime() + packetTransmissionTime);    //t3
    gptp->setRequestReceiptTimestamp(receivedTimeResponder);                    //t2
    frame->encapsulate(gptp);

    send(frame, "lowerLayerOut");
    sendPdelayRespFollowUp();
}

void EtherGPTP::sendPdelayRespFollowUp()
{
    inet::EthernetIIFrame* frame=new inet::EthernetIIFrame("gPtpPacket");
    frame->setDest(inet::MACAddress::BROADCAST_ADDRESS);
    frame->setEtherType(inet::ETHERTYPE_IPv4);  // So far INET doesn't support gPTP (etherType = 0x88f7)
    frame->setKind(PDELAY_RESP_FOLLOW_UP);

    gPtp_PdelayRespFollowUp* gptp = gPtp::newDelayRespFollowUpPacket();
    gptp->setSentTime(clockGptp->getCurrentTime());
    //gptp->setResponseOriginTimestamp(receivedTimeResponder + (SimTime)PDelayRespInterval + clockGptp->getCalculatedDrift((SimTime)PDelayRespInterval)); not use
    frame->encapsulate(gptp);

    send(frame, "lowerLayerOut");
}

/********************************/
/* Slave port related functions */
/********************************/

void EtherGPTP::slavePort(cMessage *msg)
{
    if (msg->isSelfMessage())
    {
        if(selfMsgDelayReq == msg)
        {
            sendPdelayReq();

            schedulePdelay = simTime() + pdelayInterval;
            scheduleAt(schedulePdelay, msg);
        }
    }
    else if(msg->arrivedOn("lowerLayerIn"))
    {
        if (inet::EthernetIIFrame* etherFrame = dynamic_cast<inet::EthernetIIFrame*>(msg))
        {
            cPacket* ppp;
            switch(msg->getKind())
            {
            case SYNC:
                ppp=etherFrame->decapsulate();
                if(gPtp_Sync* gptp = dynamic_cast<gPtp_Sync*>(ppp))
                {
                    processSync(gptp);
                }
                break;
            case FOLLOW_UP:
                ppp=etherFrame->decapsulate();
                if(gPtp_FollowUp* gptp = dynamic_cast<gPtp_FollowUp*>(ppp))
                {
                    processFollowUp(gptp);

                    // Send a request to send Sync message
                    // through other gPtp Ethernet interfaces
                    send(requestMsg->dup(), "gptpLayerOut");
                }
                break;
            case PDELAY_RESP:
                ppp=etherFrame->decapsulate();
                if(gPtp_PdelayResp* gptp = dynamic_cast<gPtp_PdelayResp*>(ppp))
                {
                    processPdelayResp(gptp);
                }
                break;
            case PDELAY_RESP_FOLLOW_UP:
                ppp=etherFrame->decapsulate();
                if(gPtp_PdelayRespFollowUp* gptp = dynamic_cast<gPtp_PdelayRespFollowUp*>(ppp))
                {
                    processPdelayRespFollowUp(gptp);
                }
                break;
            default:
                send(msg, "upperLayerOut");
                break;
            }
        }
        else
        {
            // Forward message to upperLayerOut gate since packet is not gPtp
            send(msg, "upperLayerOut");
        }
    }
    else if (msg->arrivedOn("upperLayerIn"))
    {
        // Forward message to lowerLayerOut gate because the message from upper layer doesn't need to be touched
        // and we are interested in only message from lowerLayerIn
        send(msg, "lowerLayerOut");
    }
}

void EtherGPTP::sendPdelayReq()
{
    // Create EtherFrame to be used to encapsulate gPtpPacket because lower layer MAC only supports EtherFrame
    inet::EthernetIIFrame* frame=new inet::EthernetIIFrame("gPtpPacket");
    frame->setDest(inet::MACAddress::BROADCAST_ADDRESS);
    frame->setEtherType(inet::ETHERTYPE_IPv4);  // So far INET doesn't support gPTP (etherType = 0x88f7)
    frame->setKind(PDELAY_REQ);

    gPtp_PdelayReq* gptp = gPtp::newDelayReqPacket();
    gptp->setSentTime(clockGptp->getCurrentTime());
    gptp->setOriginTimestamp(schedulePdelay);
    frame->encapsulate(gptp);

    send(frame, "lowerLayerOut");

    //Normally, timestamps are taken when the first bit of the message is received. In order not to make any modification to INET, it is taken at the end of the reception. It is therefore necessary to take into account the transmission time.
    double bits = (MAC_HEADER + PDELAY_REQ_PACKET_SIZE + CRC_CHECKSUM)*8;
    SimTime packetTransmissionTime = (SimTime)bits/100000000 + clockGptp->getCalculatedDrift((SimTime)bits/100000000);
    transmittedTimeRequester = clockGptp->getCurrentTime() + packetTransmissionTime;        //t1
}

void EtherGPTP::processSync(gPtp_Sync* gptp)
{
    sentTimeSync = gptp->getOriginTimestamp();
    receivedTimeSyncBeforeSync = clockGptp->getCurrentTime();
    tableGptp->setReceivedTimeSync(receivedTimeSyncBeforeSync);
}

void EtherGPTP::processFollowUp(gPtp_FollowUp* gptp)
{
    tableGptp->setReceivedTimeFollowUp(simTime());
    tableGptp->setOriginTimestamp(gptp->getPreciseOriginTimestamp());
    tableGptp->setCorrectionField(gptp->getCorrectionField());
    tableGptp->setRateRatio(gptp->getRateRatio());
    SimTime receivedTimeFup = clockGptp->getCurrentTime();

    /************** Time synchronization *****************************************
    * * Local time is adjusted using peer delay, correction field, residence time *
    * * and packet transmission time based departure time of Sync message from GM *
    *****************************************************************************/
    receivedTimeSyncBeforeSyncWithoutNoise = clockGptp->getCurrentTimeWithoutNoise(); //For logging
    SimTime correctTime = tableGptp->getOriginTimestamp() + tableGptp->getPeerDelay() + tableGptp->getCorrectionField() + (receivedTimeFup - tableGptp->getReceivedTimeSync());
    SimTime offset = clockGptp->getCurrentTime() - correctTime;
    clockGptp->adjustTime(correctTime);
    tableGptp->setReceivedTimeSync(receivedTimeSyncBeforeSync - offset);

    receivedTimeSyncAfterSync = clockGptp->getCurrentTimeWithoutNoise(); //For logging
    SimTime timeDifferenceAfter = receivedTimeSyncAfterSync - simTime();
    SimTime timeDifferenceBefore = receivedTimeSyncBeforeSyncWithoutNoise - simTime();

    EV_INFO << "############## SYNC #####################################"<< endl;
    EV_INFO << "RECEIVED TIME AFTER SYNC - " << receivedTimeSyncAfterSync << endl;
    EV_INFO << "RECEIVED SIM TIME        - " << simTime() << endl;
    EV_INFO << "ORIGIN TIME              - " << sentTimeSync << endl;
    EV_INFO << "RESIDENCE TIME           - " << receivedTimeFup - tableGptp->getReceivedTimeSync() << endl;
    EV_INFO << "CORRECTION FIELD         - " << tableGptp->getCorrectionField() << endl;
    EV_INFO << "PROPAGATION DELAY        - " << tableGptp->getPeerDelay() << endl;

    vLocalTime.record(receivedTimeSyncAfterSync);
    vMasterTime.record(sentTimeSync);
    vTimeDifference.record(receivedTimeSyncBeforeSync - sentTimeSync - tableGptp->getPeerDelay());
    vTimeDifferenceGMafterSync.record(timeDifferenceAfter);
    vTimeDifferenceGMbeforeSync.record(timeDifferenceBefore);

    EV_INFO << "############## FOLLOW_UP ################################"<< endl;
    EV_INFO << "RECEIVED TIME AFTER SYNC - " << receivedTimeSyncAfterSync << endl;
    EV_INFO << "ORIGIN TIME SYNC         - " << tableGptp->getOriginTimestamp() << endl;
    EV_INFO << "CORRECTION FIELD         - " << tableGptp->getCorrectionField() << endl;
    EV_INFO << "PROPAGATION DELAY        - " << tableGptp->getPeerDelay() << endl;
    EV_INFO << "TIME DIFFERENCE TO GM    - " << timeDifferenceAfter << endl;
    EV_INFO << "TIME DIFFERENCE TO GM BEF- " << timeDifferenceBefore << endl;
}

void EtherGPTP::processPdelayResp(gPtp_PdelayResp* gptp)
{
    receivedTimeRequester = clockGptp->getCurrentTime();            //t4
    receivedTimeResponder = gptp->getRequestReceiptTimestamp();     //t2
    transmittedTimeResponder = gptp->getSentTime();                 //t3
}

void EtherGPTP::processPdelayRespFollowUp(gPtp_PdelayRespFollowUp* gptp)
{
    //Normally, timestamps are taken when the first bit of the message is received. In order not to make any modification to INET, it is taken at the end of the reception. It is therefore necessary to take into account the transmission time.
    double bits = (MAC_HEADER + PDELAY_RESP_PACKET_SIZE + CRC_CHECKSUM)*8;
    SimTime packetTransmissionTime = (SimTime)bits/100000000 + clockGptp->getCalculatedDrift((SimTime)bits/100000000);

    //Compute neighborRateRatio
    neighborRateRatio = ((float)transmittedTimeResponder.dbl() - (float)tableGptp->getLastTransmittedTimeResponder().dbl())/((float)receivedTimeRequester.dbl() - (float)tableGptp->getLastReceivedTimeRequester().dbl());
    tableGptp->setLastTransmittedTimeResponder(transmittedTimeResponder);
    tableGptp->setLastReceivedTimeRequester(receivedTimeRequester);
    tableGptp->setNeighborRateRatio(neighborRateRatio);
    vNeighborRateRatio.record(neighborRateRatio);

    //Compute peerDelay
    peerDelay = (((receivedTimeResponder.dbl() - transmittedTimeResponder.dbl()) + tableGptp->getNeighborRateRatio().dbl()* (receivedTimeRequester.dbl() - transmittedTimeRequester.dbl())) / 2.0);

    EV_INFO << "transmittedTimeRequester (t1) - " << transmittedTimeRequester << endl;
    EV_INFO << "receivedTimeResponder    (t2) - " << receivedTimeResponder << endl;
    EV_INFO << "transmittedTimeResponder (t3) - " << transmittedTimeResponder << endl;
    EV_INFO << "receivedTimeRequester    (t4) - " << receivedTimeRequester << endl;
    EV_INFO << "packetTransmissionTime      - " << packetTransmissionTime << endl;
    EV_INFO << "PEER DELAY                  - " << peerDelay << endl;

    tableGptp->setPeerDelay(peerDelay);

    vPeerDelay.record(peerDelay);

}

