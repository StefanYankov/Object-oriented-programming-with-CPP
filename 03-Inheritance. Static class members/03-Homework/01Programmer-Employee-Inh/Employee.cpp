#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee()
{
	this->name = "default name";
	this->salary = 0.0;
}

Employee::Employee(std::string name, double salary)
{
	this->SetName(name);
	this->SetSalary(salary);
}

Employee::Employee(const Employee& rhs)
{
	this->SetName(rhs.GetName());
	this->SetSalary(rhs.GetSalary());
}

Employee& Employee::operator=(const Employee& rhs)
{
	if (this != &rhs)
	{
		this->SetName(rhs.GetName());
		this->SetSalary(rhs.GetSalary());
	}
	return *this;
}

std::string Employee::GetName() const
{
	return this->name;
}

void Employee::SetName(std::string name)
{
	if (!name.empty())
	{
		this->name = name;
	}
	else
	{
		std::cout << "Name cannot be empty";
	}
}

double Employee::GetSalary() const
{
	return this->salary;
}

void Employee::SetSalary(double salary)
{
	if (salary > 0)
	{
		this->salary = salary;
	}
	else
	{
		std::cout << "Salary must be greater than zero.";
	}
}


std::ostream& operator<<(std::ostream& out, const Employee& rhs)
{
	out << "Status: " << typeid(rhs).name() << std::endl;
	out << "Name: " << rhs.GetName() << std::endl;
	out << "Salary: " << rhs.GetSalary() << std::endl;
	return out;
}
