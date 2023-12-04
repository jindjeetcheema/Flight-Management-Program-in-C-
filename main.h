//main.h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "seat.h"
#include "flight.h"
#include "passenger.h"
#include "airline.h"

using namespace std;

int menu();
void displayHeader();
void populate_flight(const char * file_name, Flight *flight);
void wait_enter();
void trim_trailing_spaces(string& s);
void add_passenger(Flight& flight);
void remove_passenger(Flight& flight);
void save_file(const char* file_name, Flight* flight);
void cleanStandardInputStream();