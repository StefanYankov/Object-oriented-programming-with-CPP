#include "Programmer.h"

Programmer::Programmer()
	: Employee()
{
}

Programmer::Programmer(std::string name, double salary)
	:Employee(name, salary)
{
}

Programmer::Programmer(const Programmer& programmer):Employee(programmer)
{
}

Programmer& Programmer::operator=(const Programmer& programmer)
{
	if (this != &programmer)
	{
		Employee::operator=(programmer);
	}
	return *this;
}

std::string Programmer::get_name() const
{
	return GetName() + std::string(" (Programmer)");
}