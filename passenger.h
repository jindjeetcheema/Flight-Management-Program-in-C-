#ifndef MY_PASSENGER_CLASS
#define MY_PASSENGER_CLASS

#include <string>
#include "seat.h"

using namespace std;

class Passenger{
	
private:
	string f_name, l_name, phone_num;
	int id;
	Seat * seat;
	
	
	
public:
	
	void set__lname(string);
	void set_fname(string);
	void set_id(int);
	void set_phone_num(string);
	string get_lname()const;
	string get_fname()const;
	string get_phone_num()const;
	int get_id()const;
	
	void display_information();
	
};

#endif