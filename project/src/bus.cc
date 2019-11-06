#include "bus.h"

Bus::Bus(std::string name, Route * out, Route * in, int capacity, double speed) {
  name_ = name;
  outgoing_route_ = out;
  incoming_route_ = in;
  passenger_max_capacity_ = capacity;
  speed_ = speed;
  distance_remaining_ = 0;
}


bool Bus::LoadPassenger(Passenger * new_passenger) {
  if (passengers_.size() == passenger_max_capacity_){
    return false;
  }
  passengers_.push_back(new_passenger);
  return true;
}

bool Bus::Move() {
  if (distance_remaining_ <= 0) {
    return false;
  }
  distance_remaining_ -= speed_;
  return true;
}

bool Bus::IsTripComplete(){
  return false;
}
//bool Refuel() {
//  //This may become more complex in the future
//  fuel_ = max_fuel_;
//}

void Bus::Update() { //using common Update format
  Move();
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Update();
  }
}

void Bus::Report(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin(); it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
