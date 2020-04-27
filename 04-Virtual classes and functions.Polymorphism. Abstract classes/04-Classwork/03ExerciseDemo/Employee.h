#pragma once
#include <string>

class Employee {
protected:
	std::string firstname;
	std::string surname;
	float salary;
public:
	Employee() { salary = 0; };
	Employee(std::string firstname, std::string surname, float salary);
	std::string get_name();
	void set_name(std::string firstname, std::string surname);
	float get_salary();
	void set_salary(float salary);
	virtual void Print();


};
