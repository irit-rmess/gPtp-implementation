//*******************************************************************************
//* Copyright (c) 2022 IRT Saint Exupéry;
//* All rights reserved. This program and the accompanying materials
//* are made available under the terms of the MIT
//* which accompanies this distribution, and is available at
//* https://gitlab.amd.e-technik.uni-rostock.de/peter.danielis/gptp-implementation/-/blob/master/IEEE8021AS/LICENSE.txt
//*
//* Contributors:
//*    Quentin Bailleul (IRT Saint Exupéry)
//*          - initial implementation of a channel simulating a 100Base-T link
//*******************************************************************************/

package ieee8021as;

channel Channel100BaseT extends ned.DatarateChannel
{
    @class(Channel100BaseT);
    double phyJitter = default(0); //phy jitter std dev 
}
