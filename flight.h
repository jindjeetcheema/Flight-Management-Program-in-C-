#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "passenger.h"
using namespace std;

class Flight {
    private:
        vector<Passenger> passengers;
    public:
        // Add a passenger to the flight
        void add_passenger();

        // Remove a passenger from the flight
        void remove_passenger();

		// Display the information for all passengers
		void display_information();
};

#endif
