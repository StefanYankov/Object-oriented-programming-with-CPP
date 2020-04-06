#pragma once
#include "People.h"
class Student
	: public People
{
private:
	char* facultyNumber;
	double grade;
public:
	Student();
	Student(char*, char*, char*, double);
	Student(const Student&);

	~Student();
	const char* GetFacultyNumber() const;
	void SetFacultyNumber(char*);

	double GetGrade() const;
	void SetGrade(double);

	friend std::ostream& operator << (std::ostream&, const Student&);
};

std::ostream& operator << (std::ostream&, const People&);
std::ostream& operator << (std::ostream&, const Student&);
