//
// @authors: Enkhtuvshin Janchivnyambuu
//           Henning Puttnies
//           Peter Danielis
//           University of Rostock, Germany
//
// Edit by : Quentin Bailleul (IRT Saint Exupéry)
//      Copyright (c) 2022 IRT Saint Exupéry

#include "tableGPTP.h"

Define_Module(TableGPTP);

void TableGPTP::initialize(int stage)
{
    correctionField = par("correctionField");
    neighborRateRatio = par("neighborRateRatio");
    rateRatio = 1;
    peerDelay = 0;
    receivedTimeSync = 0;
    receivedTimeFollowUp = 0;
    numberOfGates = gateSize("gptpLayerIn");

    lastTransmittedTimeResponder = 0;
    lastReceivedTimeRequester = 0;
}

void TableGPTP::handleMessage(cMessage *msg)
{
    if(msg->arrivedOn("gptpLayerIn"))
    {
        for (int i = 0; i < numberOfGates; i++)
        {
            send(msg->dup(), "gptpLayerOut", i);
        }
        delete msg;
    }
}

void TableGPTP::setCorrectionField(SimTime cf)
{
    correctionField = cf;
}

SimTime TableGPTP::getCorrectionField()
{
    return correctionField;
}

void TableGPTP::setNeighborRateRatio(SimTime cf)
{
    neighborRateRatio = cf;
}

SimTime TableGPTP::getNeighborRateRatio()
{
    return neighborRateRatio;
}


void TableGPTP::setRateRatio(SimTime cf)
{
    rateRatio = cf;
}

SimTime TableGPTP::getRateRatio()
{
    return rateRatio;
}

void TableGPTP::setPeerDelay(SimTime cf)
{
    peerDelay = cf;
}

SimTime TableGPTP::getPeerDelay()
{
    return peerDelay;
}

void TableGPTP::setReceivedTimeSync(SimTime cf)
{
    receivedTimeSync = cf;
}

SimTime TableGPTP::getReceivedTimeSync()
{
    return receivedTimeSync;
}

void TableGPTP::setReceivedTimeFollowUp(SimTime cf)
{
    receivedTimeFollowUp = cf;
}

SimTime TableGPTP::getReceivedTimeFollowUp()
{
    return receivedTimeFollowUp;
}

void TableGPTP::setReceivedTimeAtHandleMessage(SimTime cf)
{
    receivedTimeAtHandleMessage = cf;
}

SimTime TableGPTP::getReceivedTimeAtHandleMessage()
{
    return receivedTimeAtHandleMessage;
}

void TableGPTP::setOriginTimestamp(SimTime cf)
{
    originTimestamp = cf;
}

SimTime TableGPTP::getOriginTimestamp()
{
    return originTimestamp;
}

void TableGPTP::setLastTransmittedTimeResponder(SimTime cf)
{
    lastTransmittedTimeResponder = cf;
}

SimTime TableGPTP::getLastTransmittedTimeResponder()
{
    return lastTransmittedTimeResponder;
}

void TableGPTP::setLastReceivedTimeRequester(SimTime cf)
{
    lastReceivedTimeRequester = cf;
}

SimTime TableGPTP::getLastReceivedTimeRequester()
{
    return lastReceivedTimeRequester;
}


