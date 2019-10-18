// Copyright 2019 3081 Staff

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

#include <iostream>
#include <string>

/**
 * @brief The main class containing methods/variables
 * for individual passengers.
 */

class Passenger {  // : public Reporter {
 public:
   /**
    * @brief Creates new instance of a Passenger
    *
    * @param[in] destination_stop_id_ Destination id
    * @param[in] name_ Name of passenger
    *
    * @return Passenger object with name and destination.
    */
  explicit Passenger(int = -1, std::string = "Nobody");
  void Update();
  void GetOnBus();
  int GetTotalWait() const;
  bool IsOnBus() const;
  int GetDestination() const;
  void Report() const;

 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
