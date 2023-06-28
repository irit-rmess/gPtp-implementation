//
// @authors: Enkhtuvshin Janchivnyambuu
//           Henning Puttnies
//           Peter Danielis
//           University of Rostock, Germany
//
// Edit by : Quentin Bailleul (IRT Saint Exupéry)
//      Copyright (c) 2022 IRT Saint Exupéry

package ieee8021as;

simple Clock
{ 
    //ClockCst
    double clockDrift=default(50);					//units : ppm
    double clockGranularity=default(8000); 			//units : ps
}
