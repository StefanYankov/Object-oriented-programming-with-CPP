#pragma once
#include "Employee.h"
class Programmer : public Employee
{
private:
public:
	Programmer();
	Programmer(std::string, double);
	Programmer(const Programmer&);
	//~Programmer(); no dynamic memory, hence not declared
	Programmer& operator=(const Programmer&);
	// seperate Setters and getters are not needed, as there is no change of functionality from base class

	std::string get_name() const;
};

