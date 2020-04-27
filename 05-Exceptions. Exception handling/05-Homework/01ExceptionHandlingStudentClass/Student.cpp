#include "Student.h"
#include "NameValueError.h"
#include "EGNValueError.h"
#include "FacultyNumberError.h"
#include <iostream>

#pragma warning(disable: 4996) // so I can use strcpy

Student::Student()
{
	this->name = new char[25];
	this->name = const_cast<char*>("Serafim Gerasimof");

	this->egn = new char[15];
	strcpy(this->egn, "2001013018");

	this->facultyNumber = new char[15];
	strcpy(this->facultyNumber, "F90000");

	this->SetGrade(2.);
}

Student::Student(char* name, char* EGN, char* facultyNumber, double grade)
{
	this->SetName(name);
	this->SetEGN(EGN);
	this->SetFacultyNumber(facultyNumber);
	this->SetGrade(grade);
}

Student::~Student()
{
	/*
	delete[] this->name;
	delete[] this->egn;
	delete[] this->facultyNumber;
	*/
}

char* Student::GetName() const
{
	return this->name;
}

void Student::SetName(char* name)
{
	int nameLength = strlen(name);
	if (nameLength < 1 || nameLength > 256)
	{
		throw NameValueError("Name must be between 1 and 256 characters.");
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

char* Student::GetEGN() const
{
	return this->egn;
}

void Student::SetEGN(char* EGN)
{
	if (this->egn != NULL)
	{
		delete[] this->egn;
	}
	int userEgnLength = strlen(EGN);
	const int egnLength = 10;
	if (userEgnLength != egnLength)
	{
		throw EGNValueError("EGN must be 10 characters long.");
	}
	this->egn = new char[strlen(EGN) + 1];
	strcpy(this->egn, EGN);

}

char* Student::GetFacultyNumber() const
{
	return this->facultyNumber;

}

void Student::SetFacultyNumber(char* facultyNumber)
{
	if (this->facultyNumber != NULL)
	{
		delete[] this->facultyNumber;
	}

	int facultyNumberLength = strlen(facultyNumber);
	if (facultyNumberLength < 6 || facultyNumberLength > 25)
	{
		throw FacultyNumberError("The faculty number has a minimum of 6 characters.");
	}
	/*
	if ((char)facultyNumber[0] != 'f' || (char)facultyNumber[0] != 'F')
	{
		throw FacultyNumberError("The faculty number must start with an 'f' or 'F'");
	}
	*/
	this->facultyNumber = new char[strlen(facultyNumber) + 1];
	strcpy(this->facultyNumber, facultyNumber);

}

double Student::GetGrade() const
{
	return this->grade;
}

void Student::SetGrade(double grade)
{
	if (grade >= 2 && grade <= 6)
	{
		this->grade = grade;
	}
	else if (grade < 2)
	{
		this->grade = 2;
	}
	else
	{
		this->grade = 6;
	}
}

bool Student::IsBetterThan(Student s) const
{
	if (grade > s.grade)
	{
		return true;
	}
	return false;
}

void Student::Print() const
{
	std::cout << "Student's name is: " << this->GetName() << std::endl;
	std::cout << "Student's EGN is: " << this->GetEGN() << std::endl;
	std::cout << "Student's faculty number is: " << this->GetFacultyNumber() << std::endl;
	std::cout << "Student's average grade: " << this->GetGrade() << std::endl;
}


void Student::Read()
{
	std::cin.ignore();
	char* tempName = new char[256];
	char* tempEGN = new char[50];
	char* tempFacultyNumber = new char[25];
	double tempGrade = 0;

	std::cout << "Enter the name of the student: ";
	std::cin.getline(tempName, 255);; std::cout <<std::endl;

	this->SetName(tempName);
	
	std::cout << "Enter the EGN of the student: ";
	std::cin >>  tempEGN; std::cout << std::endl;
	
	this->SetEGN(tempEGN);
	
	std::cout << "Enter the  faculty number of the student: ";
	std::cin >> tempFacultyNumber ; std::cout << std::endl;

	this->SetFacultyNumber(tempFacultyNumber);
	
	std::cout << "Enter the grade of the student: ";
	std::cin >>  tempGrade; std::cout << std::endl;

	this->SetGrade(tempGrade);
}

std::ostream& operator << (std::ostream& out, const Student& student)
{
	out << "Name: " << student.GetName() << " EGN: " << student.GetEGN() << std::endl
		<< " Faculty number: " << student.GetFacultyNumber() << " Grade: " << student.GetGrade() << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Student& student)
{
	char* tempName = NULL;
	char* tempEGN = NULL;
	char* tempFacultyNumber = NULL;
	double tempGrade = 0;
	in >> tempName >> tempEGN >> tempFacultyNumber >> tempGrade;

	student.SetName(tempName);
	student.SetEGN(tempEGN);
	student.SetFacultyNumber(tempFacultyNumber);
	student.SetGrade(tempGrade);
	return in;
}
