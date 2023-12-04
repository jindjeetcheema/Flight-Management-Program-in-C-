// airline.h
#ifndef MY_AIRLINE_CLASS
#define MY_AIRLINE_CLASS

#include <iostream>
#include <string>
#include <vector>
#include "flight.h"

class Airline{
private:
	string name;
	vector<Flight> flights;
	
public:
	Airline();

	void setName(string value) {name = value; } 
	string getName() const;
	vector<Flight> getFlights() const;

	void add_flight(Flight flight){flights.push_back(flight); }
};

#endif
