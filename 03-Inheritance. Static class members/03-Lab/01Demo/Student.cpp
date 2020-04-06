#include "Student.h"
#include <cassert>
#pragma warning(disable: 4996)

Student::Student() :People()
{
	//Student(char* = "No Name", char* = "No EGN", char* = "No Faculty Number", double = 2.);
	facultyNumber = new char[18];
	strcpy(facultyNumber, "No Faculty Number");
	grade = 2.;
}

Student::Student(char* name, char* EGN, char* facultyNumber, double grade)
	:People(name, EGN)
{
	this->facultyNumber = new char[strlen(facultyNumber) + 1];
	assert(this->facultyNumber != NULL);
	strcpy_s(this->facultyNumber, strlen(facultyNumber) + 1, facultyNumber);

	if (grade >= 2 && grade <= 6) 
	{ 
		this->grade = grade;
	}
	else if (grade < 2)
	{ 
		this->grade = 2;
	}
	else { 
		this->grade = 6;
	}
}

Student::Student(const Student& s) : People(s) {
	//People::People(s.get_name(), s.get_egn());
	facultyNumber = new char[strlen(s.facultyNumber) + 1];
	assert(facultyNumber != NULL);
	strcpy_s(facultyNumber, strlen(s.facultyNumber) + 1, s.facultyNumber);

	grade = s.grade;
}

Student::~Student() {
	delete[] facultyNumber;
}

void Student::SetFacultyNumber(char* f) {
	if (facultyNumber != NULL) delete[] facultyNumber;
	facultyNumber = new char[strlen(f) + 1];
	assert(facultyNumber != NULL);
	strcpy_s(facultyNumber, strlen(f) + 1, f);

}

void Student::SetGrade(double g) {
	if (g >= 2 && g <= 6) grade = g;
	else if (g < 2) grade = 2;
	else grade = 6;

}

const char* Student::GetFacultyNumber() const {
	return facultyNumber;

}

double Student::GetGrade() const {
	return grade;

}

std::ostream& operator << (std::ostream& out, const Student& s) {
	out << "Name: " << s.GetName() << " EGN: " << s.GetEGN() << std::endl
		<< " Faculty number: " << s.facultyNumber << " Grade: " << s.grade << std::endl;
	return out;
}
