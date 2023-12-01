#include "flight.h"

void Flight::add_passenger(Passenger new_passenger)
{
    // Add the Passenger object to the end of the passengers vector
    passengers.push_back(new_passenger);
}

void Flight::remove_passenger(int id) {
    //parse through the passenger vector
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

void Flight::display_seatmap() {
    // Create a 2D vector to represent the seats
    vector<vector<string> > seatmap(num_rows, vector<string>(num_cols, "|"));

    // Iterate over the passengers vector
    for (vector<Passenger>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        // Get the passenger's seat
        Seat* s = it->get_seat();
        int row = s->get_row();
        char col = s->get_column();

        // Convert the column to an index
        int col_index = col - 'A';

        // Update the seatmap
        seatmap[row-1][col_index] = "X";
    }

    // Print the seatmap
    cout << "  A B C D E F" << endl;
    for (int i = 0; i < num_rows; i++) {
        cout << i+1 << " ";
        for (int j = 0; j < num_cols; j++) {
            cout << "+" << seatmap[i][j] << "+";
        }
        cout << endl;
    }
}



