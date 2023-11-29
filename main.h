//main.h
#include <iostream>
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
void populate_flight(char * file_name, Flight flight);
void wait_enter();
void trim_trailing_spaces(string& s);