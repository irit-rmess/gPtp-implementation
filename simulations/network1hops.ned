//*******************************************************************************
//* Copyright (c) 2022 IRT Saint Exupéry;
//* All rights reserved. This program and the accompanying materials
//* are made available under the terms of the MIT
//* which accompanies this distribution, and is available at
//* https://gitlab.amd.e-technik.uni-rostock.de/peter.danielis/gptp-implementation/-/blob/master/IEEE8021AS/LICENSE.txt
//*
//* Contributors:
//*    Quentin Bailleul (IRT Saint Exupéry)
//*          - initial implementation
//*******************************************************************************/

package ieee8021as.simulations;

import ieee8021as.GPtpBridge;
import ieee8021as.GPtpMaster;
import ieee8021as.GPtpSlave;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

network network1hops
{
    @display("bgb=613,342");
    types:
        channel Ethernet100 extends ieee8021as.Channel100BaseT
        {
            datarate = 100Mbps;
            delay = 216.68ns;//25ns;	    	// Length of connection is 5 meters 
            phyJitter = 0.0000000125;//0.000000000286;
        }

    submodules:
        Slave1: GPtpBridge {
            @display("p=239.8725,159.91501");
        }
        Master: GPtpMaster {
            @display("p=64.7275,161.81876");
        }
        configurator: IPv4NetworkConfigurator {
            @display("p=51,33");
        }
    connections:

        Master.ethg++ <--> Ethernet100 <--> Slave1.ethg++;
}
