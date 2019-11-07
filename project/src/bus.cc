#include "src/bus.h"
#include "src/stop.h"

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


// checks if any remaining stops in outgoing route
bool Bus::IsRouteComplete() {
  return outgoing_route_->IsAtEnd();
}

// checks if outgoing route and incoming route are complete
bool Bus::IsTripComplete(){
  return (IsRouteComplete() && incoming_route_->IsAtEnd());
}


//bool Refuel() {
//  //This may become more complex in the future
//  fuel_ = max_fuel_;
//}

void Bus::Update() { //using common Update format

  // bus has reached a stop
  if (Move() == false){
    // bus still on outgoing route, need to prepare load/unload and figure out
    // the next stop
    if(!IsRouteComplete()) {
      Stop * cursorStop = outgoing_route_->GetDestinationStop();

      // check for passengers that need to get off
      for (std::list<Passenger *>::iterator it = passengers_.begin();
      it != passengers_.end(); it++) {
        if ((*it)->GetDestination() == cursorStop->GetId()) {
          Passenger * departing_passenger = *it;
          //departing_passenger->Report();

        // When removing the passenger, the iterator gets incremented to the
        //  next element.
        // We need to push it back so that the for loop increment places the
        // iterator at the correct next element.
          it = passengers_.erase(it);
          it--;
          delete departing_passenger;
        }
      }

      // load passengers at stop and set new distance to next stop
      cursorStop->LoadPassengers(this);
      distance_remaining_ = outgoing_route_->GetNextStopDistance();
    }
    else if (!IsTripComplete()){
      Stop * cursorStop = incoming_route_->GetDestinationStop();

      // check for passengers that need to get off
      for (std::list<Passenger *>::iterator it = passengers_.begin();
      it != passengers_.end(); it++) {
        if ((*it)->GetDestination() == cursorStop->GetId()) {
          Passenger * departing_passenger = *it;
          //departing_passenger->Report();
          it = passengers_.erase(it);
          it--;
          delete departing_passenger;
        }
      }
      cursorStop->LoadPassengers(this);
      distance_remaining_ = incoming_route_->GetNextStopDistance();
    }
    // else statement hit when bus completed trip
    // TODO: delete bus? keep updating passengers?
    else {
    }
  }

  // Update remaining passengers still on bus before finishing Bus::Update()
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
