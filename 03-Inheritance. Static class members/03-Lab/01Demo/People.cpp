#include "People.h"
#include <iostream>
#include <cassert>
#pragma warning(disable: 4996)

People::People()
{
	name = new char[8];
	strcpy(name, "No Name");
	egn = new char[7];
	strcpy(egn, "No EGN");
}

People::People(char* name, char* EGN)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);

	egn = new char[strlen(EGN) + 1];
	assert(egn != NULL);
	strcpy_s(egn, strlen(EGN) + 1, EGN);
}

People::People(const People& people) {
	name = new char[strlen(people.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(people.name) + 1, people.name);

	egn = new char[strlen(people.egn) + 1];
	assert(egn != NULL);
	strcpy_s(egn, strlen(people.egn) + 1, people.egn);
}

People::~People() {
	delete[] egn;
	delete[] name;
}

void People::SetName(char* name) {
	if (this->name != NULL) delete[] this->name;
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);
}

void People::SetEGN(char* EGN) {
	if (this->egn != NULL) delete[] this->egn;
	this->egn = new char[strlen(EGN) + 1];
	assert(this->egn != NULL);
	strcpy_s(this->egn, strlen(EGN) + 1, EGN);

}

const char* People::GetName() const {
	return name;
}

const char* People::GetEGN() const {
	return egn;
}

std::ostream& operator << (std::ostream& out, const People& people) {
	out << "Name: " << people.name << " EGN: " << people.egn << std::endl;
	return out;
}