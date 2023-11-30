#include "passenger.h"
#include "flight.h"
#include <iomanip>
#include <iostream>

Passenger::Passenger(string fname, string lname, string phone_num, int row, char seat, int id){
    first_name = fname;
    last_name = lname;
    phone_number = phone_num;
    row = row;
    column = column;
    id = id;
}

//iomanip included, this will create a table
void Passenger::display_information() {
    cout << left << setw(15) << first_name << setw(15) << last_name << setw(15) << phone_number << setw(5) << row << setw(5) << column << setw(10) << id << endl;
}
