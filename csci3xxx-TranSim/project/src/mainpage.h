/*! \mainpage TransitSim: Main Page
 *
 * \section intro_sec Project Overview
 *
 * The goal of this software project is to develop a
 * rudimentary transit simulator in which simulations can be controlled via
 * external configuration (without code change) and be visualized within a
 * graphics window.
 *
 * This is accomplished through the use of 4 main classes, bus, route, stop, and
 * passenger, which will from here on out be referred to as the "Big 4". Buses utilize
 * two collections of Passengers and Routes. Routes utilize a collection of Stops.
 * Stops utilize a collection of Passengers. Overall, Passengers are a basic "work unit"
 * for the program, traded between buses and stops to get to their destination.
 *
 * The simulation is driven by local_simulator.cc, which in this iteration sets
 * up the UMN CampusConnector routes with the appropriate stops for eastbound
 * and westbound directions. It then begins to generate buses and passengers,
 * who then each Update() and Report() for every timestep of the simulation. Timesteps are
 * used to future-proof the simulation for eventual graphic display.
 *
 *
 * \section Passenger
 *
 * The Passenger class is rather rudimentary, and is designed to be more of a pawn
 * for the other classes in the Big 4 to use. That being said, the other classes
 * can use methods defined in passenger.cc to find out a passenger's
 * destination ID, their total wait, and whether or not they are on the bus. The
 * other method, GetOnBus() is used by a stop object, which uses it when loading
 * passengers onto the current bus at that stop to switch
 * the passenger's wait time from incrementing in wait_at_stop during each Update()
 * call during timesteps to incrementing in time_on_bus_ until the passenger reaches
 * their destination. During each timestep, local_simulator will access each bus and stop
 * to Update() and Report(), who then in turn go through their containers of passengers
 * and make them Update() (simply increase their wait time by 1 depending on which
 * one they're at). The bus/stop object will then call the passengers to Report(),
 * where they print out their name, destination ID, and how long they've been waiting.
 *
 *
 * \section Route
 *
 * Routes are generated with a name, list of a stops, list of distances between those
 * stops, number of stops, and a passenger generator. Most notable of these is the
 * passenger generator, which is important to acknowledge that all passengers
 * in the simulation are generated through these passenger_generators that are
 * passed in to each route as they are being defined. Besides the generation of
 * passengers, the Route class' most important use is being used by Buses to keep
 * track of what stop they are heading to, which they access with methods from Route
 * such as GetDestinationStop() and GetNextStopDistance(). Update() and Report()
 * immediately access the container of stops and calls them to Update() and Report()
 * individually.
 *
 *
 * \section Bus
 *
 * Buses main purpose are to keep track of the stops they have to make, which are
 * stored in a container and modified (stops popped) when stops are reached. A bus
 * knows it reaches a stop when it moves (in Update() method), which simply updates
 * the distance remaining by subtracting the speed. Update() also iterates through
 * passengers and makes them Update().When a bus reaches a stop, it will call on its passengers
 * to check if it is their stop and then prepare to continue on by grabbing the
 * next available stop in the queue provided by the route container, switching directions
 * if no more stops in a certain direction. The bus accesses pointers to stops in
 * order to begin transferring the passenger points from the stop to the bus.
 *
 *
 * \section Stop
 *
 * Stops main purpose is to be stored in a list in the Route object, and also
 * maintain a list of Passenger objects. Stops will be called by buses to load
 * passengers onto the bus and provide an ID for the bus to check for passengers
 * that need to exit. Stops are also called by Routes, which generate passengers,
 * to add those passengers to the stop's passenger list and be responsible for
 * having them Report() and Update() when the stop is called to Report() and Update().
 */
