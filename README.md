# GPS-project
## Description
This Project implements a GPS tracking system using TM4C123G LaunchPad, the system should stores the moved trajectory after power-on until a destination point is reached and calculate the distance between the starting point and the destination.
Implementation is in embedded C, and no built-in drivers were used, all implemented code was from scratch.
## Code Porcedures
	
1. After power on, the system configures the following interfaces:
   *   UART to interface with the GPS module.
   *   UART to interface with PC.
   *   Digital Output for built-in LED.
2. The system reads GPS module data and waits until there is a GPS fix
3. The first point read with GPS is set as the start point.
4. The system keeps periodically reading the coordinates from the GPS module to get the trajectory
   *   Systick timer is used to control the refresh rate.
5. After the destination point is reached, the system stops appending new points and a lamp is lit.

