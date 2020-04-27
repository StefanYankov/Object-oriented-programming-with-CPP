#include "Employee.h"
#include <string.h>
#include <exception>
#include <iostream>
#include <iomanip>
#pragma warning(disable: 4996)

Employee::Employee()
{
	this->SetName("default name");
	this->salary = 0.0;
	this->SetTenure(0, 0);
}

Employee::Employee(const char* name, double salary, int tenureYears, int tenureMonths)
{
	this->SetName(name);
	this->SetSalary(salary);
	this->SetTenure(tenureYears, tenureMonths);
}

Employee::~Employee()
{
	if (name!=nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

Employee::Employee(const Employee& rhs)
{
	this->SetName(rhs.GetName());
	this->SetSalary(rhs.GetSalary());
	this->SetTenure(rhs.tenure[0], rhs.tenure[1]);
}

Employee& Employee::operator=(const Employee& rhs)
{
	if (this != &rhs)
	{
		this->SetName(rhs.GetName());
		this->SetSalary(rhs.GetSalary());
		this->SetTenure(rhs.tenure[0], rhs.tenure[1]);

	}
	return *this;
}

char* Employee::GetName() const
{
	return name;
}

void Employee::SetName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

double Employee::GetSalary() const
{
	return this->salary;
}

void Employee::SetSalary(double salary)
{
	if (salary >0)
	{
		this->salary = salary;
	}
	else
	{
		throw std::exception("Salary cannot be a negative or zero value.");
	}
}

int Employee::GetTenure(int index)
{
	if (index < 0 || index > 1)
	{
		throw std::exception("Index can only be 0 for years and 1 for months.");
	}
	return tenure[index];
}

void Employee::SetTenure(int years, int months)
{
	if (years < 0 || months < 0)
	{
		throw std::exception("Months/Years cannot be a negative or zero value.");
	}
	int tempYears = years;
	int tempMonths = months;
	// years 2 // months 36
	while (tempMonths > 12)
	{
		tempMonths -= 12;
		tempYears++;
	}
	this->tenure[0] = tempYears;
	this->tenure[1] = tempMonths;
}
void Employee::Print() const
{
	std::cout << "Employee name is: " << this->GetName() << std::endl
		<< "Employee salary is:" << std::fixed << std::setprecision(2) << this->GetSalary() << std::endl;
}

void Employee::PrintAll()
{
	Print();
		std::cout << "Employee tenure is:" << this->GetTenure(0) << " years and " << this->GetTenure(1) << " months." << std::endl;
}


