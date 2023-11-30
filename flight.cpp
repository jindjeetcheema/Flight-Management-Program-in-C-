#include "flight.h"
#include <iomanip>

void Flight::add_passenger(){
    string first_name;
    string last_name;
    string phone_number;
    int row;
    char column;
    int id;
    
	
	cout << "Please enter the passenger id: "<<endl;
	cin >>id;
	
	cout << "Please enter the passenger first name: "<<endl;
	cin >> first_name;

	cout << "Please enter the passenger last name: "<<endl;
	cin >> last_name;

	cout << "Please enter the passenger phone number: "<<endl;
	cin >> phone_number;
	
	cout << "Enter passenger desired row: "<<endl;
	cin >> row;

    Passenger new_passenger(first_name, last_name, phone_number, row, column, id);
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
