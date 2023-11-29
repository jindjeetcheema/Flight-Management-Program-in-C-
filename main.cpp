//Term Project - Group #7
#include "main.h"


int main()
{
	Flight  f;
	displayHeader();
	populate_flight ("flight_info.txt", f);
	cout << "finished";
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
				wait_enter();
				break;
			case 3:
				//adds a new passenger
				wait_enter();
				break;
			case 4:
				//removes an existing passenger
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
	//wait_enter();
}


void wait_enter()
{
	//will wait until the user enters a newline value
	//FIXME: Does not work
	cout << "<<< Press Return to Continue>>>";
	while (getchar() != '\n');
	
}

void populate_flight(char * file_name, Flight flight)
{
	char s[21], f[10];
	string fname, lname, phone_num, flight_id;
	int row, id, flight_rows, flight_cols;
	char col;
	
	ifstream in (file_name, ios::in);
	if (in.fail()){
		cout << "Unable to read file. Please try again.";
		exit(1);
	}
	//in class example:
	//reading in flight information
	in.get(f, 10, '\n');
	flight_id = f;
	in >> flight_rows;
	in >> flight_cols;



	//reading in passenger information and 
	//#TODO:place passenger info into classes
	do{

		in.get(s, 21, '\0');
		fname = s;
		trim_trailing_spaces(fname);
		if (in.eof()) break;

		in.get(s, 21, '\n');
		if(in.eof()) break;
		lname = s;
		trim_trailing_spaces(lname);
		
		in.get(s, 21, '\n');
		if(in.eof()) break;
		phone_num = s;
		trim_trailing_spaces(phone_num);
		
		in >> row;
		col = in.get();
		if(in.eof()) break;
		
		in >> id;
	
	}while(!in.eof());
}


void trim_trailing_spaces(string &s){
	while((s.at(s.size()-1) == ' '|| s.at(s.size()-1) == '\n') && s.size()> 0){
		s.pop_back();
	}
		
}