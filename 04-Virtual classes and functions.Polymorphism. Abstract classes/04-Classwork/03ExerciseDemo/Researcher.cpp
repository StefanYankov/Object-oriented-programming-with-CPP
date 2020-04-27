#include "Researcher.h"
#include <ostream>
#include <iostream>

Researcher::Researcher(std::string firstname, std::string surname, float salary, std::string university, std::string thesis)
: Employee(firstname, surname, salary)
{
	this->university = university;
	this->thesis = thesis;
}

std::string Researcher::get_university()
{
	return university;
}

void Researcher::set_university(std::string university)
{
	this->university = university;
}

std::string Researcher::get_thesis()
{
	return this->thesis;
}

void Researcher::set_thesis(std::string thesis)
{
	this->thesis = thesis;
}

void Researcher::Print()
{
	Employee::Print();
	std::cout << "Role is researcher with PhD at " << university << " on \"" << thesis << "\" thesis." << std::endl;
}
