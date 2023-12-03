#include "passenger.h"

Passenger::Passenger(string fname, string lname, string phone_num, int pass_row, char pass_col, int pass_id) : first_name(fname), last_name(lname),
phone_number(phone_num), id(pass_id), row(pass_row), col(pass_col)
{
    seat = new Seat(row, col);
    assert(seat != nullptr);
}

Passenger::~Passenger()
{
    delete seat;
    seat = nullptr;
}

Passenger::Passenger(const Passenger& src):first_name(src.first_name), last_name(src.last_name), phone_number(src.phone_number),
id(src.id), row(src.row), col(src.col){
    seat = new Seat(row, col);
    assert(seat!=nullptr);
}

Passenger& Passenger::operator=(const Passenger& rhs){
    if (this != &rhs)
    {
        delete seat;
        first_name = rhs.first_name;
        last_name = rhs.last_name;
        phone_number = rhs.phone_number;
        id = rhs.id;
        row = rhs.row;
        col = rhs.col;
        seat = new Seat(row, col);
        assert(seat!=nullptr);
    }
    return *this;
}

void Passenger::set_seat(int row, char col){
    seat = new Seat(row, col);
    assert(seat!=nullptr);
}

//iomanip included, this will create a table
void Passenger::display_information() {
    int row = seat->get_row();
    char column = seat->get_column();
    cout << left << setw(15) << first_name << setw(15) << last_name << setw(15) << phone_number << setw(5) << row << setw(5) << column << setw(10) << id << endl;
}
