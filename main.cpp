//Term Project - Group #7

#include "main.h"
#include "seat.h"
#include "flight.h"
#include "passenger.h"
#include "airline.h"


int main()
{
	Airline a;
	Flight  f;
	a.add_flight(f);
	displayHeader();
	const char * file = "flight_info.txt";
	populate_flight (file, &f);
	//demo code. November 23
	int choice = 1;
	while (choice){
		switch(menu()){ //switch will perform each different case depending on the return value of menu()
			case 1:
				//display the flight seat map
				f.display_seatmap();
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
				save_file("flight_info.txt", &f);
				wait_enter();
				break;
			case 6:
				//Quits
				choice = 0;
				break;
			default:
				cout << "\nInvalid match. Please Try Again.\n";
				break;
		}
	}
}
		

int menu()
{
	cin.clear();
	int choice = -1;	
	cout << "Please select one of the following options:\n";
	cout <<"1. Display Flight Seat Map.\n";
	cout <<"2. Display Passengers Information.\n";
	cout <<"3. Add a New Passenger.\n";
	cout <<"4. Remove an Existing Passenger.\n";
	cout <<"5. Save data.\n";
	cout <<"6. Quit.\n";
	cout <<"\nEnter your choice (1, 2, 3, 4, 5 or 6): ";
	cin >> choice;
	cleanStandardInputStream();
	return choice;
}

void displayHeader()
{
	cout << "Version: 1.0\n";
	cout << "Term Project - Flight Management Program in C++\n";
	cout << "Produced By: Cody Casselman, Jindjeet Cheema, Taiwu Chen\n";
	wait_enter();
}


void wait_enter()
{
	//will wait until the user enters a newline value
	cout << "\n<<< Press Return to Continue>>>\n";
	while (cin.get() != '\n');
}

void populate_flight(const char * file_name, Flight * flight){
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
	trim_trailing_spaces(flight_id);
	in >> flight_rows;
	in >> flight_cols;
	
	in.ignore();

	flight->set_id(flight_id);
	flight->set_num_rows(flight_rows);
	flight->set_num_cols(flight_cols);
	// Initialize the seatmap
	flight->initialize_seatmap();
	
	
	//reading in passenger information
	do{

		//reading first name
		in.get(s, 21, '\0');
		if (in.eof()) break;
		fname = s;
		trim_trailing_spaces(fname);
		

		//reading last name
		in.get(s, 21, '\0');
		if(in.eof()) break;
		lname = s;
		trim_trailing_spaces(lname);
		
		//reading phone number
		in.get(s, 21, '\0');
		if(in.eof()) break;
		phone_num = s;
		trim_trailing_spaces(phone_num);
		
		//reading passenger row, column, id
		in >> row;
		col = in.get();
		if(in.eof()) break;

		in >> id;
		
		in.ignore();
		// Ignore the newline character at the end of the line

		flight->add_passenger(fname, lname, phone_num, row, col, id);
		
	}while(!in.eof()); //will perform the above actions until it reaches the end of file
	in.close();

}


void trim_trailing_spaces(string &s){
	//REQUIRES: String reference s
	//Promises: String s will be manipulated so that all whitespace characters at the end of the string
	//will be removed
	while((s.at(s.size()-1) == ' '|| s.at(s.size()-1) == '\n') && s.size()> 0){
		s.pop_back();
	}
		
}

void add_passenger(Flight& flight){
	int id, row;
	string first_name, last_name, phone_number;
	char col;

	cout << "Please enter the passenger id: (5 Numbers) "<<endl;
	cin >>id;
	cleanStandardInputStream();

	cout << "Please enter the passenger first name: (Maximum 20 Characters) "<<endl;
	cin >> first_name;
	first_name = first_name;
	cleanStandardInputStream();

	cout << "Please enter the passenger last name: (Maximum 20 Characters) "<<endl;
	cin >> last_name;
	cleanStandardInputStream();

	//input for phone number
	cout << "Please enter the passenger phone number: (Must Follow Standard XXX-XXX-XXXX Formatting) "<<endl;
	cin >> phone_number;
	cleanStandardInputStream();
	//checking phone number follows format
	while(phone_number[3] != '-' || phone_number[7] != '-'){
		cout << "Invalid Formatting, please try again" << endl;
		cin >> phone_number;
		cleanStandardInputStream();
	}

	cout << "Enter passenger desired row: (Must be From 1-20) "<<endl;
	cin >> row;
	cleanStandardInputStream();
	while(row < 1 || row > 20){
		cout << "Error: input is out of bounds. Please try again" << endl;
		cin >> row;
		cleanStandardInputStream();
	}

	cout << "Enter passenger desired column: (Must be Capital Letter from A-E)"<<endl;
	cin >> col;
	cleanStandardInputStream();
	while(col < 'A' && col > 'E'){
		cout << "Error: input is out of bounds. Please try again" << endl;
		cin >> row;
		cleanStandardInputStream();
	}
	
	flight.add_passenger(first_name, last_name, phone_number, row, col, id);
}

void remove_passenger(Flight& flight){
	int id;
	cout << "Please enter the id of the passenger that needs to be removed: \n";
    	cin >> id;
	cleanStandardInputStream();
	flight.remove_passenger(id);
}

void save_file(const char* file_name, Flight* flight){
	vector<Passenger> passengers = flight->get_passengers();

	ofstream out(file_name, ios::out);

	if(out.fail()){
		cout << "Unable to write to file. Please try again.\n";
		exit(1);
	}

	out << left << setw(9) <<  flight->get_id() << setw(6) << flight->get_num_rows() << flight-> get_num_cols() << endl;

	//write all of the data back into the file from the flight class
	for(size_t i = 0; i < passengers.size(); i++){
		Passenger passenger = passengers.at(i);
		out << setw(20) << passenger.get_first_name()
		<< setw(20) << passenger.get_last_name() 
		<< setw(20) << passenger.get_phone_number()  
		<< setw(4) << passenger.get_seat()->disp_seat()
		<< setw(5) <<passenger.get_id()
		<< endl;
	}
	out << "\n";
	out.close();
}

void cleanStandardInputStream(){
	cin.clear();
	int leftover;
	do{
		leftover = cin.get();
	}while(leftover != '\n' && leftover != EOF);
}