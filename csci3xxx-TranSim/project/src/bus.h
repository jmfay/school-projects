/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/passenger.h"
#include "src/route.h"
#include "src/stop.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class Bus {
 public:
   /**
   * @brief Creates new instance of a Bus
   *
   * @param[in] string holding the name of the bus
   * @param[in] Route* First half of trip
   * @param[in] Route* second half of trip
   * @param[in] int capacity of the bus
   * @param[in] double speed of the bus
   *
   * @return Bus object with name, route pointers to keep track of stops/distances,
   * a max capacity, and a speed.
   */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
   /**
   * @brief Called by a Stop who passes in a pointer to the passenger it wants
   * to remove from its stop.
   *
   * @param[in] Passenger* Passenger to be loaded
   *
   * @return true if bus has room and passenger was added, false otherwise
   */
  bool LoadPassenger(Passenger *);  // returning revenue delta
  /**
  * @brief Check if first half of bus's trip is complete (outgoing_route_)
  *
  * @return true if no remaining stops in outgoing_route_'s stop list, false otherwise
  */
  bool IsRouteComplete();
  /**
  * @brief Check if bus's trip is fully complete
  *
  * @return true if no remaining stops in outgoing_route_ and incoming_route_ stop lists, false otherwise
  */
  bool IsTripComplete();
  /**
  * @brief Updates the distance_remaining_ to next stop.
  *
  * @return true if distance updated successfully, false if no remaining distance to travel to next stop.
  */
  bool Move();
  /**
  * @brief Moves the bus, and if at stop, begins to load/unload passengers and figure out
  * next distance to travel.
  */
  void Update();
  /**
  * @brief Print name of bus, its speed, distance to next stop, and # of passengers
  * then iterates through passengers to Report()
  *
  * @param[in] std::ostream out, object to print out to, usually std::cout
  */
  void Report(std::ostream&);

 private:
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
};
#endif  // SRC_BUS_H_
