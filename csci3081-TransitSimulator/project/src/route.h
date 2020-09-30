/**
 * @file route.h
 *
 * @Copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_

#include <list>
#include <iostream>
#include <string>

#include "./passenger_generator.h"
#include "./stop.h"

class PassengerGenerator;
class Stop;

class Route {
 public:
  /**
  * @brief Creates new instance of a Route
  *
  * @param[in] string Name of route
  * @param[in] Stop** Container of stop pointers for Route
  * @param[in] double* Container of distance between stops
  * @param[in] int Number of stops in route
  * @param[in] PassengerGenerator* Generator to randomly place passengers at stops in route each timestep
  * @return Route object with name, list of stops, list of distances between stops, number of stops, and a passenger generator.
  */
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator *);
  /**
  * @brief Create a copy of the route calling method. Used by "master copy" of a route to be
  * provided to a bus to track its stops and distances.
  *
  * @return Route object to be provided to bus object
  */
  Route * Clone();
  /**
  * @brief Iterates through all stops to Update() and generats passengers for the route
  */
  void Update();
  /**
  * @brief Calls on stops in stops_ to report
  */
  void Report(std::ostream&);
  /**
  * @brief Used by bus objects to check if no remaining stops in stops_
  *
  * @return true of stops_ is empty, false otherwise
  */
  bool IsAtEnd();
  /**
  * @brief Change value of destination_stop_ to next stop in stops_
  */
  void NextStop();  // Change destination_stop_ to next stop
  /**
  * @brief Used by buses to get pointer to stop when it reaches it so it can
  * begin to unload/load passengers. Pops stop from stops_ queue so when called
  * again will return next stop.
  *
  *
  * @return Pointer to the stop at front of queue
  */
  Stop * GetDestinationStop();    // Get pointer to next stop
  // double GetTotalRouteDistance() const;
  /**
  * @brief Retrieve the appropiate distances_between_ member to return to bus object
  *
  * @return double value representing distance to next stop in route.
  */
  double GetNextStopDistance();

 private:
   /**
   * @brief Calls on PassengerGenerator pointer to figure out where to create/place
   * new passengers.
   *
   * @return int number of passengers created
   */
  int GenerateNewPassengers();       // generates passengers on its route
  PassengerGenerator * generator_;
  std::list<Stop *> stops_;
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;
  int num_stops_;
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;
  // double trip_time_; // derived data - total distance travelled on route
};
#endif  // SRC_ROUTE_H_
