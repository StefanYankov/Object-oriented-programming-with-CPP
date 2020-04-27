#pragma once
#include "Employee.h"

class Researcher
	: public Employee
{
private:
	std::string university;
	std::string thesis;
public:
	Researcher() {};
	Researcher(std::string firstname, std::string surname, float salary, std::string university, std::string thesis);
	std::string get_university();
	void set_university(std::string university);
	std::string get_thesis();
	void set_thesis(std::string thesis);
	void Print();
};
