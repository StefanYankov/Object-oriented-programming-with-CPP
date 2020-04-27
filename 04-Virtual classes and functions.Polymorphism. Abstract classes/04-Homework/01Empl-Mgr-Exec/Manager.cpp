#include "Manager.h"
#include <iostream>

Manager::Manager()
	: Employee()
{
	this->departament = "default departament";
}

Manager::Manager(const char* name, double salary, int tenureYears, int tenureMonths, std::string departament)
	:Employee(name,salary,tenureYears,tenureMonths)
{
	this->SetDepartament(departament);
}

Manager::Manager(const Manager& manager)
	: Employee(manager)
{
	this->SetDepartament(manager.GetDepartament());
}

Manager& Manager::operator=(const Manager& manager)
{
	if (this != &manager)
	{
		Employee::operator=(manager);
		this->SetDepartament(manager.GetDepartament());
	}
	return *this;
}

std::string Manager::GetDepartament() const
{
	return this->departament;
}

void Manager::SetDepartament(std::string departament)
{
	if (departament.length() > 0)
	{
		this->departament = departament;
	}
	else
	{
		throw std::exception("Departament cannot be empty.");
	}
}

void Manager::Print() const
{
	Employee::Print();
	std::cout << "departament: " << this->GetDepartament() << std::endl;

}

