#include "Student.h"
#include <iostream>
#pragma warning(disable: 4996)

Student::Student()
{
	name = new char[2];
	name = const_cast<char*>("");
	grade = 2;
}

Student::Student(const char* n, double g) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	if (g >= 2 && g <= 6) grade = g;
	else if (g < 2) grade = 2;
	else grade = 6;
}

void Student::read() {
	std::cout << "Enter the name of the student: ";
	name = new char[256];
	std::cin.getline(name, 255);
	std::cout << "Enter the grade of the student: ";
	do {
		std::cin >> grade;
	} while (grade < 2 || grade > 6);
	std::cin.ignore();
}

void Student::setName(char* n) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

void Student::setGrade(double g) {
	if (g >= 2 && g <= 6) grade = g;
	else if (g < 2) grade = 2;
	else grade = 6;
}

bool Student::is_better_than(Student s) const {
	if (grade > s.grade) return true;
	return false;
}

void Student::print() const {
	std::cout << "Student's name: " << name << std::endl;
	std::cout << "Student's average grade: " << grade << std::endl;
}

char* Student::getName() const {
	return name;
}

double Student::getGrade() const {
	return grade;
}
