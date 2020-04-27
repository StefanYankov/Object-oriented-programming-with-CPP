#pragma once
#include "Employee.h"

class Engineer
: public Employee
{
private:
	float cppknowladge;
	unsigned int years;
	std::string type;
public:
	Engineer() { years = 0; cppknowladge = 0; };
	Engineer(std::string firstname, std::string surname, float salary, float cppknowladge, unsigned int years, std::string type);
	float get_cppknowladge();
	void set_cppknowladge(float cppknowladge);
	unsigned get_years();
	void set_years(unsigned years);
	std::string get_type();
	void set_type(std::string type);
	void Print();
};
