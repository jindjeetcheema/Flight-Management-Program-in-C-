#include "flight.h"
#include "passenger.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Flight::add_passenger(){
	int id, row, colomn;
	string f_name, l_name, phone_num;
	
	
	cout << "Please enter the passenger id: "<<endl;
	cin >>id;
	
	cout << "Please enter the passenger first name: "<<endl;
	cin >> f_name;

	cout << "Please enter the passenger last name: "<<endl;
	cin >> l_name;

	cout << "Please enter the passenger phone number: "<<endl;
	cin >> phone_num;
	
	cout << "Enter passenger desired row: "<<endl;
	cin >> row;

    Passenger new_passenger(f_name, l_name, phone_num, row, colomn, id);
    // Add the Passenger object to the end of the passengers vector
    passengers.push_back(new_passenger);
}

void Flight::remove_passenger() {
    int id;

    cout << "Please enter the id of the passenger that needs to be removed: ";
    cin >> id;

    for (int i = 0; i < passengers.size(); i++) {
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
