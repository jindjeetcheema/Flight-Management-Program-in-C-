#include "seat.h"
Seat::Seat(int r, char c){
    row = r;
    column = c;
    status = true;
}

Seat::Seat() : row(0), column(0), status(false){}

