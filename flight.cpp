#include "flight.h"

Flight::Flight() : flight_id("\0"), num_rows(0), num_cols(0) {
    // Initialize the seatmap with empty seats
    seatmap = vector<vector<string> >(num_rows, vector<string>(num_cols, "|"));
}


Flight::~Flight()
{
    passengers.erase(passengers.begin(), passengers.begin() + passengers.size());
}

void Flight::initialize_seatmap() {
    // Initialize the seatmap with empty seats
    seatmap = vector<vector<string> >(num_rows, vector<string>(num_cols, "|"));
}


void Flight::add_passenger(string fname, string lname, string phone_num, int row, char col, int pass_id) {
    // Add the Passenger object to the end of the passengers vector
    Passenger new_passenger(fname, lname, phone_num, row, col, pass_id);
    passengers.push_back(new_passenger);
    
    // Update the seatmap
    seatmap[row - 1][col - 'A'] = "X";
}


void Flight::remove_passenger(int id) {
    // Parse through the passenger vector
    for (size_t i = 0; i < passengers.size(); i++) {
        if (passengers[i].get_id() == id) {
            // Update the seatmap
            Seat* s = passengers[i].get_seat();
            seatmap[s->get_row() - 1][s->get_column() - 'A'] = "|";
            
            // Delete the elements in passengers list
            passengers.erase(passengers.begin() + i);
            break;
        }
    }
}



void Flight::display_information() {
    cout << left << setw(15) << "First Name" << setw(15) << "Last Name" << setw(14) << "Phone" << setw(5) << "Row" << setw(5) << "Seat" << setw(10) << "ID" << endl;
    for (Passenger& p : this->passengers) {
        p.display_information();
    }
}

void Flight::display_seatmap() {
    // Print the seatmap
    cout << "      Aircraft Seat Map" << endl;
    cout << "     A   B   C   D   E   " << endl;
    
    for (int i = 0; i < num_rows; i++) {
        cout << "   +---+---+---+---+---+" << endl;
        cout << i+1 << " ";
        for (int j = 0; j < num_cols; j++) {
            cout << "| " << seatmap[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "   +---+---+---+---+---+" << endl;
}


