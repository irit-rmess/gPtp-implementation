OMNeT++ Simulation Model of the General Precision Time Protocol (gPTP)
===============================================================


This model of the General Precision Time Protocol (gPTP), well known by IEEE 802.1AS standard was implemented by Enkhtuvshin Janchivnyambuu, Henning Puttnies, and Peter Danielis at the University of Rostock in March 2018 (https://gitlab.amd.e-technik.uni-rostock.de/peter.danielis/gptp-implementation). 
In 2022, this model was improved and assess with measurements on real switches supporting IEEE802.1AS by Quentin Bailleul (IRT Saint Exupéry), Katia Jaffrès-Runser (IRIT), Jean -Luc Scharbarg (IRIT) and Philippe Cuenot (IRT Saint Exupéry). For more detailed information about this project, please refer to the folloing open access research papers:

"A Simulation Model of IEEE 802.1AS gPTP for Clock Synchronization in OMNeT++",
Henning Puttnies, Peter Danielis, Enkhtuvshin Janchivnyambuu, Dirk Timmermann,
In Proceedings of the OMNeT++ Community Summit 2018, Vol. 56, pp. 63-72, Pisa, Italy, September 2018

"Assessing a precise gPTP simulator with IEEE802.1AS hardware measurements",
Quentin Bailleul, Katia Jaffrès-Runser, Jean -Luc Scharbarg, Philippe Cuenot,
In Proceedings of the 11th European Congress on Embedded Real Time Software and Systems (ERTS 2022), Toulouse, France.



Requirements
------------------------
- OMNeT++ 5.2 
- INET 3.6.3


Hints
------------------------
- If you are still getting path errors, try to create a new project. Afterwards, copy the src and simulation directories in this new project and try to build. This project only depends on OMNeT++ and INET. Therefore, OMNeT's default path values already do a good job.
- Try to run the software in the release mode
