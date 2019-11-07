// Copyright 2019 fayxx092
#include "src/route.h"

Route::Route(std::string name, Stop ** stops, double * distances, int num_stops,
   PassengerGenerator * pg) {
  for (int i = 0; i < num_stops; i++) {
    stops_.push_back(stops[i]);
  }
  for (int i = 0; i < num_stops - 1; i++) {
    distances_between_.push_back(distances[i]);
  }

  name_ = name;
  num_stops_ = num_stops;
  generator_ = pg;
}

// iterate through each stop in the route and then generate passengers for the
// route.
void Route::Update() {
  for (std::list<Stop *>::iterator it = stops_.begin(); it != stops_.end();
    it++) {
    (*it)->Update();
  }
  generator_->GeneratePassengers();
}

// creates a copy of the route to be passed to a new bus object to modify
Route* Route::Clone() {
  return new Route(*this);
}

// check if no more stops left in Route list since we pop them as bus moves
// along route
bool Route::IsAtEnd() {
  return stops_.empty();
}

// TODO(fayxx092): Use NextStop in combination with GetDestinationStop?
void Route::NextStop() {
  return;
  // destination_stop_ = GetDestinationStop();
}

// stores stop being pointed to by next stop, then pops it from stop_ and
// returns new pointer
Stop * Route::GetDestinationStop() {
  Stop * destStop = (stops_.front());
  stops_.pop_front();
  destination_stop_ = destStop;
  return destStop;
}

// method used to give to bus for its distance_remaining till next stop
// need to keep distances_between_ intact so can still
// access full route distance
double Route::GetNextStopDistance() {
  if (destination_stop_index_ > (num_stops_ - 2)) {
    return -1;
  }
  std::list<double>::iterator it = distances_between_.begin();

// Advance the iterator by desination_stop_index_ positions to find distance,
  std::advance(it, destination_stop_index_);
  destination_stop_index_++;
  return (*it);
}

void Route::Report(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  out << "Num stops: " << num_stops_ << std::endl;
  int stop_counter = 0;
  for (std::list<Stop *>::const_iterator it = stops_.begin();
    it != stops_.end(); it++) {
    (*it)->Report(out);
    stop_counter++;
  }
}
