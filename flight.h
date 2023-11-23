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
	int num_of_rows;
	
	
public:
	
	void print_map();
	void display_flight();
	
	
};
#endif