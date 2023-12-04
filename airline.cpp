// airline.cpp
#include "airline.h"

Airline::Airline() {
	name = "WestJet";
}

string Airline::getName() const {
	return name;
}

vector<Flight> Airline::getFlights() const {
	return flights;
}
