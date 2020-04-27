#include "Executive.h"
#include <iostream>

Executive::Executive()
	: Manager()
{
}

Executive::Executive(const char* name, double salary, int tenureYears, int tenureMonths, std::string departament)
	: Manager(name, salary, tenureYears, tenureMonths, departament)
{
}

Executive::Executive(const Executive& executive)
	: Manager(executive)
{
}

Executive& Executive::operator=(const Executive& executive)
{
	if (this != &executive)
	{
		Employee::operator=(executive);

	}
	return *this;
}

void Executive::Print() const
{
	std::cout << "Executive" << std::endl;
	Manager::Print();
}
