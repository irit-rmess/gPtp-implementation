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

#ifndef CHANNEL100BASET
#define CHANNEL100BASET

#include "omnetpp/csimulation.h"
#include "omnetpp/cchannel.h"
#include <omnetpp/cdataratechannel.h>

class Channel100BaseT: public omnetpp::cDatarateChannel {
    double phyJitter;

public:
    Channel100BaseT();
    virtual ~Channel100BaseT();
    void rereadPars();
    virtual void processMessage(omnetpp::cMessage *msg, omnetpp::simtime_t t, omnetpp::cChannel::result_t& result);
    void handleParameterChange(const char *);

private:
    double rand_normal(double mean, double stddev);
};

#endif /* CHANNEL100BASET */
