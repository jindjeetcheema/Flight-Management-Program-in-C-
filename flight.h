#ifndef MY_FLIGHT_CLASS
#define MY_FLIGHT_CLASS

#include <vector>
#include <string>
#include "seat.h"
#include "passenger.h"


using namespace std;

class Flight{
private:
	
	
	string id;
	int num_rows;
	int num_cols;
	vector<Passenger> passengers;
	vector<vector<Seat>> map;
	
	
public:


	void set_rows(int value);
	void set_cols(int value);
	void set_id(string value);
	
	int get_rows()const;
	int get_cols()const;
	string get_id()const;
	
	void print_map();
	
	void add_passenger(Passenger passenger);
	
	void remove_passenger(int pass_id);
	
	void display_passenger_info(int pass_id);
	
	
	
};
#endif