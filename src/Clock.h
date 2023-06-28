//
// @authors: Enkhtuvshin Janchivnyambuu
//           Henning Puttnies
//           Peter Danielis
//           University of Rostock, Germany
//
// Edit by : Quentin Bailleul (IRT Saint Exupéry)
//      Copyright (c) 2022 IRT Saint Exupéry

#ifndef __IEEE8021AS_CLOCK_H_
#define __IEEE8021AS_CLOCK_H_

#include <omnetpp.h>

using namespace omnetpp;

class Clock : public cSimpleModule
{
    SimTime lastAdjustedClock;
    SimTime lastSimTime;
    SimTime clockDrift;
    double granularity;

  protected:
    virtual void initialize();
    double getRandDouble(double HIGH, double LOW);


  public:
    SimTime getCurrentTime();
    SimTime getCurrentTimeWithoutNoise();
    SimTime getCalculatedDrift(SimTime value);
    void adjustTime(SimTime value);
    SimTime getAdjustTimeToGranularity(SimTime value);
};

#endif
