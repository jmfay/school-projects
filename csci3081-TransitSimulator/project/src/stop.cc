// Copyright 2019 fayxx092
#include <iostream>
#include <vector>

#include "src/stop.h"

Stop::Stop(int id, double longitude, double latitude) : id_(id),
 longitude_(longitude), latitude_(latitude) {  // Defaults to
  // Westbound Coffman Union stop
  // no initialization of list of passengers necessary
}

int Stop::LoadPassengers(Bus * bus) {
    // loading some passengers onto a bus while passengers still at stop
    int loaded = 0;
    while (!(passengers_.empty())) {
      // double checks to make sure bus isn't full (returns count if at
      // max capacity)
      if (bus->LoadPassenger(passengers_.front())) {
        passengers_.front()->GetOnBus();
        passengers_.pop_front();
        loaded++;
      } else {
          return loaded;
      }
    }
    // returns count if stop runs out of passengers to give
    return loaded;
  }


int Stop::AddPassengers(Passenger * pass) {
    // add the passenger to the stop
    passengers_.push_back(pass);
    return 1;
}

void Stop::Update() {
  for (std::list<Passenger *>::iterator it = passengers_.begin(); it !=
    passengers_.end(); it++) {
    (*it)->Update();
  }
}

int Stop::GetId() const {
  return id_;
}

void Stop::Report(std::ostream& out) const {
  out << "ID: " << id_ << std::endl;
  out << "Passengers waiting: " << passengers_.size() << std::endl;
  for (std::list<Passenger *>::const_iterator it = passengers_.begin();
    it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
