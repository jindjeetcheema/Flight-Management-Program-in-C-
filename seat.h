#ifndef MY_SEAT_CLASS
#define MY_SEAT_CLASS

using namespace std;

class Seat{
private:
	int row;
	char column;
	bool status;

public:

	Seat(int r, int c);

	void set_row(int value);
	void set_column(int value);
	void set_status(char value);
	int get_row()const;
	char get_column()const;
	char get_status()const;
		
};
#endif