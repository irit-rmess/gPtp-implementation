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

network network3hops
{
    @display("bgb=756,342");
    types:
        channel Ethernet100 extends ieee8021as.Channel100BaseT
        {
            datarate = 100Mbps;
            delay = 216.68ns;
            phyJitter = 0.0000000125;
        }

    submodules:
        Slave3: GPtpBridge {
            @display("p=664.8725,159.91501");
        }
        Slave2: GPtpBridge {
            @display("p=464.8725,159.91501");
        }
        Slave1: GPtpBridge {
            @display("p=264.8725,159.91501");
        }
        GM: GPtpMaster {
            @display("p=64.7275,159.91501");
        }
        configurator: IPv4NetworkConfigurator {
            @display("p=51,33");
        }
    connections:

        GM.ethg++ <--> Ethernet100 <--> Slave1.ethg++;
        Slave1.ethg++ <--> Ethernet100 <--> Slave2.ethg++;
        Slave2.ethg++ <--> Ethernet100 <--> Slave3.ethg++;
}
