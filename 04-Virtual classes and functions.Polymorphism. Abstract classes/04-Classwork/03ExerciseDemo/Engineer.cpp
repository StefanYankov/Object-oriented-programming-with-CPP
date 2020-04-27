#include "Engineer.h"
#include <iostream>

Engineer::Engineer(std::string firstname, std::string surname, float salary, float cppknowladge, unsigned int years, std::string type)
: Employee(firstname, surname, salary)
{
	this->cppknowladge = cppknowladge;
	this->years = years;
	this->type = type;
}

float Engineer::get_cppknowladge()
{
	return cppknowladge;
}

void Engineer::set_cppknowladge(float cppknowladge)
{
	this->cppknowladge = cppknowladge;
}

unsigned Engineer::get_years()
{
	return years;
}

void Engineer::set_years(unsigned years)
{
	this->years = years;
}

std::string Engineer::get_type()
{
	return type;
}

void Engineer::set_type(std::string type)
{
	this->type = type;
}

void Engineer::Print()
{
	Employee::Print();
	std::cout << "Role is " << type << " engineer with " << cppknowladge << " out of 10 knowladge of C++, " << years << " of experienc. " << std::endl;
}