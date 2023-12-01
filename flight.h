#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "passenger.h"
#include "seat.h"

class Flight {
    private:
        vector<Passenger> passengers;
        string flight_id;
        int num_rows, num_cols;

    public:

        //default constructor
        Flight() : flight_id("\0"), num_rows(0), num_cols(0){}
        //setter functions
        void set_id(string f_id) {flight_id = f_id; }
        void set_num_rows(int value) {num_rows = value; };
        void set_num_cols(int value) {num_cols = value; };
        //getter functions
        string get_id()const {return flight_id;}
        int get_num_rows()const {return num_rows; }
        int get_num_cols()const {return num_cols; }

        // Add a passenger to the passenger vector
        void add_passenger(Passenger new_passenger);

        // Remove a passenger from the passenger vector
        void remove_passenger(int id);

		// Display the information for all passengers
		void display_information();

        // Display the seat map
        void display_seatmap();
};

#endif
