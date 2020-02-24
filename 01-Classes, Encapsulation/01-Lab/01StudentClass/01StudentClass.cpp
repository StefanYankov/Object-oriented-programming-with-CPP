#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
	/*
	Student myStudent;
	myStudent.ToString();

	const char* name2 = "Stefan Yankoff";
	const char* major2 = "Informatics";

	cout << endl;

	Student myStudent2(name2, 3423423, major2);
	myStudent2.ToString();

	cout << endl;
	*/

	char* name = new char[50];
	unsigned facultyNumber = 0;
	char* major = new char[25];
	/*
	cout << "Please enter name for the student: ";
	cin.getline(name, 49);

	cout << "Please enter the student's faculty number: ";
	cin >> facultyNumber;
	cin.ignore();

	cout << "Please enter the major of the student: ";
	cin.getline(major, 24);

	Student myStudent3(name, facultyNumber, major);
	myStudent3.ToString();

	Student* ptr = new Student(const_cast<char*>(name), facultyNumber, const_cast<char*>(major));
	ptr->ToString();

	delete[] ptr;
	ptr = nullptr;
	*/

	Student* repositoryOfStudents[3];

	for (size_t i = 0; i < 3; i++)
	{
		cout << "Please enter name for the student: ";
		cin.getline(name, 49);

		cout << "Please enter the student's faculty number: ";
		cin >> facultyNumber;
		cin.ignore();

		cout << "Please enter the major of the student: ";
		cin.getline(major, 24);

		repositoryOfStudents[i] = new Student(const_cast<char*>(name), facultyNumber, const_cast<char*>(major));
		repositoryOfStudents[i]->ToString();
	}

	for (size_t i = 0; i < 3; i++)
	{
		delete repositoryOfStudents[i];
		repositoryOfStudents[i] = nullptr;
	}

	return 0;
}
