//
// @authors: Enkhtuvshin Janchivnyambuu
//           Henning Puttnies
//           Peter Danielis
//           University of Rostock, Germany
//
// Edit by : Quentin Bailleul (IRT Saint Exupéry)
//      Copyright (c) 2022 IRT Saint Exupéry

#define _USE_MATH_DEFINES

#include "Clock.h"
#include<cmath>
#include <cstdlib>
#include <ctime>
#include <random>

Define_Module(Clock);

/* Initialize the clock */
void Clock::initialize(){
    granularity = par("clockGranularity");    // units ps
    clockDrift = par("clockDrift");           // units ppm
    //clockDrift = getRandDouble(10,-10);

    lastSimTime = 0;

    // Initialize clock at a random start time
    if (clockDrift == 0){
        lastAdjustedClock = 0; // GM clock should be at the same time as simtime
    }
    else {
        lastAdjustedClock = SimTime(getRandDouble(200, -200));
    }
}

/* Return a random double between LOW and HIGH */
double Clock::getRandDouble(double HIGH, double LOW){
    double randDouble = LOW + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HIGH-LOW)));
    return randDouble;
}

/* Return drifted current time based on last adjusted time */
SimTime Clock::getCurrentTime(){
    SimTime duration = simTime() - lastSimTime;
    SimTime currentTime = lastAdjustedClock + duration + duration.dbl()*clockDrift.dbl()/1000000.0;
    return getAdjustTimeToGranularity(currentTime);
}

/* Return drifted current time based on last adjusted time without granularity for logging purpose */
SimTime Clock::getCurrentTimeWithoutNoise(){
    SimTime duration = simTime() - lastSimTime;
    SimTime currentTime = lastAdjustedClock + duration + duration.dbl()*clockDrift.dbl()/1000000.0;
    return currentTime;
}

/* Return drifted current time based on last adjusted time */
SimTime Clock::getCalculatedDrift(SimTime duration){
    return duration.dbl()*clockDrift.dbl()/1000000.0;
}


/* Adjust time based on last adjusted time */
void Clock::adjustTime(SimTime value){
    lastAdjustedClock = value;
    lastSimTime = simTime();
}


/* Adjust time value to the clock granularity*/
SimTime Clock::getAdjustTimeToGranularity(SimTime value){
    if (granularity == 0){
        return value;
    }
    else{
        int64_t q = floor(value.inUnit(SIMTIME_PS)/(granularity)) ;
        //If the quotient reaches the maximum integer on 64 bits
        if (q < - 9223372036854000000){
            char text[128];
            sprintf(text,"Can't compute the current time with granularity. Reduce the sim-time-limit. (Event number: %lld)", getSimulation()->getEventNumber());
            getSimulation()->getActiveEnvir()->alert(text);
        }

        SimTime timeWithGranularity = q*int64_t(granularity)*pow(10,-12);
        return timeWithGranularity;
    }
}
