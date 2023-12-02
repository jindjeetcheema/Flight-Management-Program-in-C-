#include "flight.h"

Flight::~Flight()
{
    passengers.erase(passengers.begin(), passengers.begin()+size(passengers));
}

void Flight::add_passenger(string fname, string lname, string phone_num, int row, char col, int pass_id)
{
    // Add the Passenger object to the end of the passengers vector
    Passenger new_passenger(fname, lname, phone_num, row, col, pass_id);
    passengers.push_back(new_passenger);
    
}

void Flight::remove_passenger(int id) {
    //parse through the passenger vector
    for (size_t i = 0; i < passengers.size(); i++) {
        if (passengers[i].get_id() == id) {
            // Delete the elements in passengers list
            passengers.erase(passengers.begin() + i);
            break;
        }
    }
}


void Flight::display_information() {
    cout << left << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "Phone" << setw(5) << "Row" << setw(5) << "Seat" << setw(10) << "ID" << endl;
    for (Passenger& p : this->passengers) {
        p.display_information();
    }
}
