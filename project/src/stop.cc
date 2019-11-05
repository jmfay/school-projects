#include <iostream>
#include <vector>

#include "stop.h"

Stop::Stop(int id, double longitude, double latitude) : id_(id), longitude_(longitude), latitude_(latitude) { //Defaults to Westbound Coffman Union stop
  // no initialization of list of passengers necessary
}

void Stop::LoadPassengers(Bus * bus) {
		while(!(passengers_.empty())){
			passengers_.front()->GetOnBus();
			bus->LoadPassenger(passengers_.front());
			passengers_.pop_front();
		}
	  //loading some passengers onto a bus
}


int Stop::AddPassengers(Passenger * pass) {
	  //add the passenger to the stop
		passengers_.push_back(pass);
    return 1;
}

void Stop::Update() {
  for (std::list<Passenger *>::iterator it = passengers_.begin(); it != passengers_.end(); it++) {
    (*it)->Update();
  }
}

int Stop::GetId() const{
  return id_;
}

void Stop::Report(std::ostream& out) const {
  out << "ID: " << id_ << std::endl;
  out << "Passengers waiting: " << passengers_.size() << std::endl;
  for(std::list<Passenger *>::const_iterator it = passengers_.begin(); it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
