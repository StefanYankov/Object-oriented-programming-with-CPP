#include "Human.h"

#include <cstring>

Human::Human(char* name, char* familyName, bool hasYChromosome, bool hasBrother)
{
	this->SetName(name);
	this->SetFamilyName(familyName);
	this->SetHasYChromosome(hasYChromosome);
	this->SetHasBrother(hasBrother);
}

Human::~Human()
{
	if (this->name != nullptr) {
		delete[] name;
	}

	if (this->familyName != nullptr) {
		delete[] familyName;
	}
}

bool Human::IsHasBrother() const
{
	return hasBrother;
}

void Human::SetHasBrother(bool hasBrother)
{
	this->hasBrother = hasBrother;
}

Human& Human::operator+(const Human& male)
{
	if (IsHasBrother()) {
		this->SetFamilyName(male.GetFamilyName());
	}
	else {
		////neinata, -, na muja
		char* familyNameWithDash = new char[strlen(this->GetFamilyName()) + 1 + strlen(male.GetFamilyName()) + 1];
		strcpy_s(familyNameWithDash, strlen(this->GetFamilyName()) + 1, this->GetFamilyName());
		strcat_s(familyNameWithDash, strlen(this->GetFamilyName()) + 2, "-");
		strcat_s(familyNameWithDash, strlen(this->GetFamilyName()) + 2 + strlen(male.GetFamilyName()), male.GetFamilyName());

		this->SetFamilyName(familyNameWithDash);
	}

	return *this;
}

char* Human::GetName() const
{
	return name;
}

void Human::SetName(char* name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

char* Human::GetFamilyName() const
{
	return familyName;
}

void Human::SetFamilyName(char* familyName)
{
	if (this->familyName != nullptr)
	{
		delete[] this->familyName;
	}

	this->familyName = new char[strlen(familyName) + 1];
	strcpy_s(this->familyName, strlen(familyName) + 1, familyName);
}

bool Human::IsHasYChromosome() const
{
	return hasYChromosome;
}

void Human::SetHasYChromosome(bool hasYChromosome)
{
	this->hasYChromosome = hasYChromosome;
}
