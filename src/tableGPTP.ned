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
// this will be used to store a value of correctionField and neighborRateRatio
//
simple TableGPTP
{
    parameters:
        string nodeType = default("SlaveNode"); // MasterNode, BridgeNode and SlaveNode
        double correctionField = default(0);
        double neighborRateRatio = default(1);
        double syncReceivedTime = default(0);
    gates:
        input gptpLayerIn[];
        output gptpLayerOut[];
}
