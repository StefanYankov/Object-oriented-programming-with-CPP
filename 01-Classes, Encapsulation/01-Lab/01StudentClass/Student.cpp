#include "Student.h"
#include <iostream>

Student::Student(const char* name, unsigned facultyNumber, const char* major)
{
	this->name = name;
	this->facultyNumber = facultyNumber;
	this->major = major;
}

Student::Student()
{
	this->name = "";
	this->facultyNumber = 0;
	this->major = "";
}

Student::~Student()
{
	std::cout << "Student " << this->name << " has been deleted." << std::endl;
}

void Student::ToString()
{
	std::cout << this->name << " with a faculty number F" << this->facultyNumber << " and major " << this->major << "." << std::endl;
}
