//
// @authors: Enkhtuvshin Janchivnyambuu
//           Henning Puttnies
//           Peter Danielis
//           University of Rostock, Germany
//
// Edit by : Quentin Bailleul (IRT Saint Exupéry)
//      Copyright (c) 2022 IRT Saint Exupéry

package ieee8021as;

//
// This module is a part of EthernetInterfaceGPTP compound module and is placed between MAC and Encap/Queue
// Time-aware switch shall have EthernetInterfaceGPTP module instead of standard WiredNIC 
//
simple EtherGPTP
{
    parameters:
        int portType = default(0); 			// 0-Passive port by default. 2-Master port, 1-Slave port, 0-Passive port
      
        double syncInterval = default(0.125);
        double pdelayInterval = default(1);
        
        int edge100BaseT = default(-1); 	//Value between 0 and 4, -1 for random value between 0 and 4
    gates:
        input upperLayerIn; // @labels(EtherFrame);		// Connect to Queue if Queue exists or Encap if Queue doesn't
        output upperLayerOut; // @labels(EtherFrame); 	// Connect to Encap
        input lowerLayerIn; //@labels(EtherFrame);		// Connect to Mac output
        output lowerLayerOut; //@labels(EtherFrame);	// Connect to Mac input
        input gptpLayerIn;
        output gptpLayerOut;
}
