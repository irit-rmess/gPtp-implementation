/*******************************************************************************
 * Copyright (c) 2022 IRT Saint Exupéry;
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the MIT
 * which accompanies this distribution, and is available at
 * https://gitlab.amd.e-technik.uni-rostock.de/peter.danielis/gptp-implementation/-/blob/master/IEEE8021AS/LICENSE.txt
 *
 * Contributors:
 *    Quentin Bailleul (IRT Saint Exupéry)
 *          - initial implementation of a channel simulating a 100Base-T link
 *******************************************************************************/


#include "Channel100BaseT.h"

#include "EtherGPTP.h"
#include "omnetpp/cexception.h"
#include "omnetpp/cmodule.h"
#include "omnetpp/cgate.h"
#include<cmath>
#include <random>

using std::ostream;

Define_Channel(Channel100BaseT);

/* Constructor */
Channel100BaseT::Channel100BaseT() : cDatarateChannel() {
    phyJitter = 0;
}

/* Destructor */
Channel100BaseT::~Channel100BaseT() {}

void Channel100BaseT::rereadPars(){
    cDatarateChannel::rereadPars();

    phyJitter = par("phyJitter");
    if (phyJitter < 0)
        throw omnetpp::cRuntimeError(this, "Negative delay %s", phyJitter);
}

void Channel100BaseT::handleParameterChange(const char *){
    rereadPars();
}

/* Send the message through the link */
void Channel100BaseT::processMessage(omnetpp::cMessage *msg, omnetpp::simtime_t t, omnetpp::cChannel::result_t& result){
    //Get the EtherGPTP instance from the other side of the link
    omnetpp::cGate *gate = this->getSourceGate();
    omnetpp::cModule *neighborModule =  gate->getPathEndGate()->getPreviousGate()->getOwnerModule()->getSubmodule("etherGPTP");

    if(neighborModule != NULL){
        EtherGPTP *EtherNeighborModule = omnetpp::check_and_cast<EtherGPTP *>(neighborModule);

        double defaultDelay = par("delay");
        double stdPhyJitter = par("phyJitter");
        int edge = EtherNeighborModule->getEdge100BaseT();

        //Compute the latency caused by the buffering (due to the edge on which PPL lock) and the PHY jitter
        double latency = edge*0.000000008 + rand_normal(0.0, stdPhyJitter);
        double delayWithLatency = defaultDelay + latency;

        EV_INFO << "############## CHANNEL INFO ################################"<< omnetpp::endl;
        EV_INFO << "edge                          : " << edge << omnetpp::endl;
        EV_INFO << "standard deviation phy jitter : " << stdPhyJitter << omnetpp::endl;
        EV_INFO << "link delay                    : " << delayWithLatency << omnetpp::endl;

        //Set delay to the compute delay with latency and send the message
        cDatarateChannel::setDelay(delayWithLatency);
        cDatarateChannel::handleParameterChange("");
        cDatarateChannel::processMessage(msg, t, result);

        //Restore delay to default value
        cDatarateChannel::setDelay(defaultDelay);
        cDatarateChannel::handleParameterChange("");
    }
    else{
        cDatarateChannel::processMessage(msg, t, result);
    }
}

/* Return a random double following a normal distribution  */
double Channel100BaseT::rand_normal(double mean, double stddev){
    //Box muller method
    static double n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        double x, y, r;
        do
        {
            x = 2.0*rand()/RAND_MAX - 1;
            y = 2.0*rand()/RAND_MAX - 1;

            r = x*x + y*y;
        }
        while (r == 0.0 || r > 1.0);
        {
            double d = sqrt(-2.0*log(r)/r);
            double n1 = x*d;
            n2 = y*d;
            double result = n1*stddev + mean;
            n2_cached = 1;
            return result;
        }
    }
    else
    {
        n2_cached = 0;
        return n2*stddev + mean;
    }
}



