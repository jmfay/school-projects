// Copyright 2019 3081 Staff

#include "src/passenger.h"

#include <iostream>
#include <string>


int Passenger::count_ = 0;

// Passenger::Passenger(Stop * dest = NULL, std::string name = "Nobody") {
Passenger::Passenger(int destination_stop_id, std::string name): name_(name),
 destination_stop_id_(destination_stop_id), wait_at_stop_(0), time_on_bus_(0),
  id_(count_) {
  count_++;
}

void Passenger::Update() {
  if (IsOnBus()){
    time_on_bus_++;
  }
  else{
    wait_at_stop_++;
  }
}

//method assumes update will be called during the same frame GetOnBusis called
void Passenger::GetOnBus() {
  time_on_bus_ = 1;
  // prevents doubling of wait time at instance where passenger is at stop then
  // gets on bus
  if(wait_at_stop_ >= 0){
  wait_at_stop_--;
  }
}

int Passenger::GetTotalWait() const {
  // -1 accounts for the setting of time_on_bus_ to 1 initially
  return (wait_at_stop_ + time_on_bus_);
}

bool Passenger::IsOnBus() const {
  if (time_on_bus_ > 0){
    return true;
  }
  return false;
}

int Passenger::GetDestination() const {
  return destination_stop_id_;
}

void Passenger::Report() const {
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Destination: " << destination_stop_id_ << std::endl;
  std::cout << "Total Wait: " << GetTotalWait() << std::endl;
  std::cout << "\tWait at Stop: " << wait_at_stop_ << std::endl;
  std::cout << "\tTime on bus: " << time_on_bus_ << std::endl;
}
