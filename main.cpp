//Term Project - Group #7

#include "main.h"
#include "seat.h"
#include "flight.h"
#include "passenger.h"
#include "airline.h"
#include "seat.cpp"
#include "flight.cpp"
#include "passenger.cpp"
#include "airline.cpp"

int main()
{
	Flight  f;
	displayHeader();
	populate_flight ("flight_info.txt", f);
	//demo code. November 23
	int choice = 1;
	while (choice){
		switch(menu()){ //switch will perform each different case depending on the return value of menu()
			case 1:
				//display the flight seat map
				wait_enter();
				break;
			case 2:
				//display passengers information
				f.display_information();
				wait_enter();
				break;
			case 3:
				//adds a new passenger
				add_passenger(f);
				wait_enter();
				break;
			case 4:
				//removes an existing passenger
				remove_passenger(f);
				wait_enter();
				break;
			case 5:
				//Saves data to file
				wait_enter();
				break;
			case 6:
				//Quits
				choice = 0;
				break;
			default:
				cout << "Invalid match. Please Try Again.";
		}
	}
}
		

int menu()
{
	int choice = -1;
	cout << "Please select one of the following options:\n";
	cout <<"1. Display Flight Seat Map.\n";
	cout <<"2. Display Passengers Information.\n";
	cout <<"3. Add a New Passenger.\n";
	cout <<"4. Remove an Existing Passenger.\n";
	cout <<"5. Save data.\n";
	cout <<"6. Quit.\n";
	cout <<"\n Enter your choice:: (1, 2, 3, 4, 5 or 6) ";
	cin >>choice;
	return choice;
}

void displayHeader()
{
	cout << "Version: 1.0\n";
	cout << "Term Project - Flight Management Program in C++\n";
	cout << "Produced By: Cody Casselman, Jindjeet Cheem, Taiwu Chen\n\n";
	wait_enter();
}


void wait_enter()
{
	//will wait until the user enters a newline value
	cout << "<<< Press Return to Continue>>>\n";
	while (cin.get() != '\n');
}

void populate_flight(char * file_name, Flight flight){
	/*
	Requires:
	char * file_name is a string which holds the name of a file in the working directory
	flight: ...

	Promises:
	function will read flight information and return a flight object, containing the populated flight
	as read from the input file
	*/
	char s[21], f[10];
	string fname, lname, phone_num, flight_id;
	int row, id, flight_rows, flight_cols;
	char col;
	
	//creating istream object in. which will read various values from the input file
	ifstream in (file_name, ios::in);
	if (in.fail()){
		cout << "Unable to read file. Please try again.";
		exit(1);
	}

	//reading in flight information
	in.get(f, 10, '\n');
	flight_id = f;
	in >> flight_rows;
	in >> flight_cols;
	
	flight.set_id(flight_id);
	flight.set_num_rows(flight_rows);
	flight.set_num_cols(flight_cols);

	//reading in passenger information
	//#TODO:place passenger info into classes
	do{

		//reading first name
		in.get(s, 21, '\0');
		if (in.eof()) break;
		fname = s;
		trim_trailing_spaces(fname);
		

		//reading last name
		in.get(s, 21, '\n');
		if(in.eof()) break;
		lname = s;
		trim_trailing_spaces(lname);
		
		//reading phone number
		in.get(s, 21, '\n');
		if(in.eof()) break;
		phone_num = s;
		trim_trailing_spaces(phone_num);
		
		//reading passenger row, column, id
		in >> row;
		col = in.get();
		if(in.eof()) break;

		in >> id;

		Passenger new_passenger(fname, lname, phone_num, nullptr, id); //FIXME: nullptr bullshit
		new_passenger.set_seat(row, col); //FIXME find way to streamline
		flight.add_passenger(new_passenger);
		
	}while(!in.eof()); //will perform the above actions until it reaches the end of file


}


void trim_trailing_spaces(string &s){
	//REQUIRES: String reference s
	//Promises: String s will be manipulated so that all whitespace characters at the end of the string
	//will be removed
	while((s.at(s.size()-1) == ' '|| s.at(s.size()-1) == '\n') && s.size()> 0){
		s.pop_back();
	}
		
}

void add_passenger(Flight flight){
	int id, row;
	string first_name, last_name, phone_number;
	char col;

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

	cout << "Enter passenger desired column: "<<endl;
	cin >> col;
}

void remove_passenger(Flight flight){
	int id;
	cout << "Please enter the id of the passenger that needs to be removed: ";
    cin >> id;

	flight.remove_passenger(id);
}