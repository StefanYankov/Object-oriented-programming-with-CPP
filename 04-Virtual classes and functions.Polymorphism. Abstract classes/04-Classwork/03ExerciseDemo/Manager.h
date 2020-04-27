#pragma once
#include <string>
#include "Employee.h"

class Manager
: public Employee
{
private:
	unsigned int num_of_meetings;
	unsigned int num_of_holidays;
	
public:
	Manager() { num_of_meetings = 5; num_of_holidays = 25; };
	Manager(std::string firstname, std::string surname, float salary, unsigned int num_of_meetings, unsigned int num_of_holidays);
	unsigned int get_get_num_of_meetings();
	void set_num_of_meetings(unsigned int num_of_meetings);
	unsigned int get_get_num_of_holidays();
	void set_num_of_holidays(unsigned int num_of_holidays);
	void Print();

};
