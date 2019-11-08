/**
 * @file stop.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_STOP_H_
#define SRC_STOP_H_

#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"

class Bus;

class Stop {
 public:
   /**
   * @brief Creates new instance of a Stop
   *
   * @param[in] int holding the stop's id
   * @param[in] int holding stop's longitude coordinate
   * @param[in] int holding stop's latitude coordinate
   *
   * @return Stop object with id and coordinates.
   */
  explicit Stop(int, double = 44.973723, double = -93.235365);
  // Adding passengers to the stop (from the generator)
  /**
  * @brief Returns id_ of stop, used by buses to compare with their passengers
  * destination IDs
  *
  * @return int representing id of the stop
  */
  int GetId() const;
  /**
  * @brief Begins to remove passengers from passengers_ and pass them to bus object
  * to be loaded on. Calls GetOnBus() method for passengers it loads. Continues
  * until bus is full or no more passengers at stop.
  *
  * @param[in] Bus* Bus object currently at this stop on its route
  *
  * @return total number of passengers returned
  */
  int LoadPassengers(Bus *);
  /**
  * @brief Called by Route object to place a passenger it generated into the stop's
  * passenger container
  *
  * @param[in] Passenger* to be added to stop's passenger container
  *
  * @return 1 after passenger is added to stop's containers
  */
  int AddPassengers(Passenger *);
  /**
  * @brief Iterate through passenger container to Update()
  */
  void Update();
  /**
  * @brief Print stop's ID and number of passengers remaining, then iterate through passenger
  * container and make them report
  *
  * @param[in] std::ostream out, object to print out to, usually std::cout
  */
  void Report(std::ostream&) const;

 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;
  double latitude_;  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // SRC_STOP_H_
