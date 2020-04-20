#pragma once
#include <string>
class Employee
{
private:
	std::string name;
	double salary;
public:
	Employee();
	Employee(std::string, double);
	Employee(const Employee&);
	//~Employee(); no dynamic memory, hence not declared
	Employee& operator=(const Employee&);

	std::string GetName() const;
	void SetName(std::string);

	double GetSalary() const;
	void SetSalary(double);
};

std::ostream& operator<< (std::ostream&, const Employee&);