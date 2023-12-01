#ifndef MY_SEAT_CLASS
#define MY_SEAT_CLASS

#include <iostream>
using namespace std;

class Seat{
private:
	int row;
	char column;
	bool status;

public:
	//constructor and default constructor
	Seat(int r, char c);
	Seat();
	//setter functinos
	void set_row(int value) {row = value;}
	void set_column(char value) {column = value;}
	void set_status(bool value) {status = value;}
	//getter functions
	int get_row()const {return row;}
	char get_column()const {return column;}
	bool get_status()const {return status;}
	
};
#endif