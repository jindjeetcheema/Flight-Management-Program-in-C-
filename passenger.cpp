#include "passenger.h"
#include <iomanip>

Passenger::Passenger(string fname, string lname, string phone_num,Seat * s, int id){
    first_name = fname;
    last_name = lname;
    phone_number = phone_num;
    seat = s;
    id = id;
}

//iomanip included, this will create a table
void Passenger::display_information() {
    int row = seat->get_row();
    char column = seat->get_column();
    cout << left << setw(15) << first_name << setw(15) << last_name << setw(15) << phone_number << setw(5) << row << setw(5) << column << setw(10) << id << endl;
}
