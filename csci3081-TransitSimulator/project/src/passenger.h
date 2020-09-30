
/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

#include <iostream>
#include <string>

class Passenger {  // : public Reporter {
 public:
  /**
  * @brief Constructs a passenger with a standard name and id.
  *
  *
  * @param[in] int holding an id number
  * @param[in] string holding a name of a created passenger.
  *
  */
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
    * @brief Increments wait_at_stop_ or time_on_bus_, depending on which object
    * passenger is being stored in.
    *
    *
    */
  void Update();
  /**
    * @brief Called when passenger being transferred from stop object container
    * to bus object container. Causes passenger to begin updating time_on_bus_
    * instead of wait_at_stop_
    *
    */
  void GetOnBus();
  /**
    * @brief Returns sum of wait_at_stop_ and time_on_bus_, used for Report()
    *
    * @return Total # of timesteps passenger has waited at stop & on bus
    */
  int GetTotalWait() const;
  /**
    * @brief Checks if passenger has begun incrementing time_on_bus_
    *
    * @return true if time_on_bus_ != 0, false otherwise
    */
  bool IsOnBus() const;
  /**
    * @brief Returns destination_stop_id_, used by buses when at stops to see
    * if a passenger needs to be removed from its passenger list (equivalent to
    * getting off the bus).
    *
    * @return Returns destination_stop_id_
    */
  int GetDestination() const;
  /**
    * @brief Passenger will print out their name, destination, time waited at stop,
    * and time waited on bus.
    *
    * @param[in] std::ostream out, object to print out to, usually std::cout
    *
    * @return Passenger object with name and destination.
    */
  void Report(std::ostream&) const;

 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;   // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
