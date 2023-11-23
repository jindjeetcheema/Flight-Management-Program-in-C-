//Term Project - Group #7

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <iostream>
#include "seat.h"
#include "flight.h"
#include "passenger.h"
#include "airline.h"

using namespace std;



int menu();
void displayHeader();
Flight populate_flight(char * file_name);

int main()
{
	Flight * f;
	displayHeader();
	f = populate_flight ("file_name");
	
	//demo code. November 23
	int choice = 1;
	while (choice!=0){
		switch(menu()){ //switch will perform each different case depending on the return value of menu()
			case 1:
				//display the flight seat map
				pressEnter();
				break;
			case 2:
				//display passengers information
				PressEnter();
				break;
			case 3:
				//adds a new passenger
				PressEnter();
				break;
			case 4:
				//removes an existing passenger
				PressEnter();
				break;
			case 5:
				//Saves data to file
				PressEnter();
				break;
			case 6:
				//Quits
				choice = 0;
				PressEnter();
				break;
			default:
				cout << "Invalid match. Please Try Again.";
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
	cout << "woohoo";
}

Flight populate_flight(char * file_name)
{
	ifstream in (file_name, ios::in);
	
	if (in.fail()){
		cout << "Cannot open the file";
		exit(1)
	}
	
}