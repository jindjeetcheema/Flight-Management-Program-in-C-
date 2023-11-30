#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include "flight.h"
#include "seat.h"
using namespace std;

class Passenger {
private:
    string first_name;
    string last_name;
    string phone_number;
    int id;
    Seat * seat;
    
public:
    // Constructor
    Passenger(string fname, string lname, string phone, Seat * s, int id);
    
    // Getter functions
    string get_first_name() { return first_name; }
    string get_last_name() { return last_name; }
    string get_phone_number() { return phone_number; }
    Seat * get_seat() { return seat; }
    int get_id() { return id; }
    
    // Display a single passenger information
    void display_information();
};

#endif
