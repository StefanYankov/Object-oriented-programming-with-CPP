#include "Manager.h"
#include <ostream>
#include <iostream>

Manager::Manager(std::string firstname, std::string surname, float salary, unsigned int num_of_meetings, unsigned int num_of_holidays)
: Employee(firstname, surname, salary)
{
	this->num_of_meetings = num_of_meetings;
	this->num_of_holidays = num_of_holidays;
}

unsigned int Manager::get_get_num_of_meetings()
{
	return num_of_meetings;
}

void Manager::set_num_of_meetings(unsigned int num_of_meetings)
{
	this->num_of_meetings = num_of_meetings;
}

unsigned int Manager::get_get_num_of_holidays()
{
	return num_of_meetings;
}

void Manager::set_num_of_holidays(unsigned int num_of_holidays)
{
	this->num_of_holidays = num_of_holidays;
}

auto Manager::Print() -> void
{
	Employee::Print();
	std::cout << "Role manager with " << num_of_meetings << " meetings per week and " << num_of_holidays <<
		" holidays per year." << std::endl;
}
