#include "Employee.h"
#include <ostream>
#include <iostream>

Employee::Employee(std::string firstname, std::string surname, float salary)
{
	this->firstname = firstname;
	this->surname = surname;
	this->salary = salary;
}

std::string Employee::get_name()
{
	return firstname + " " + surname;
}

void Employee::set_name(std::string firstname, std::string surname)
{
	this->firstname = firstname;
	this->surname = surname;
}

float Employee::get_salary()
{
	return salary;
}

void Employee::set_salary(float salary)
{
	this->salary = salary;
}

void Employee::Print()
{
	std::cout << "Employee: " << get_name() << " with salary of " << salary << std::endl;
}
