#include "CAnimal.h"
#include <string>
#include <iostream>

CAnimal::CAnimal()
{
	name = "default animal";
	heigth = 5;
	weigth = 15;
	CAnimal::numberOfAnimals++;
}

CAnimal::CAnimal(std::string name, double heigth, double weigth)
{
	this->name = name;
	this->heigth = heigth;
	this->weigth = weigth;
	CAnimal::numberOfAnimals++;
}

std::string CAnimal::GetName() const
{
	return name;
}
void CAnimal::SetName(std::string name)
{
	this->name = name;
}

double CAnimal::GetHeigth() const
{
	return heigth;
}
void CAnimal::SetHeigth(double heigth)
{
	this->heigth = heigth;
}

double CAnimal::GetWeigth() const
{
	return weigth;
}
void CAnimal::SetWeigth(double weigth)
{
	this->weigth = weigth;
}

int CAnimal::numberOfAnimals = 0;

void CAnimal::SetAll(std::string name, double heigth, double weigth)
{
	this->name = name;
	this->heigth = heigth;
	this->weigth = weigth;
}
void CAnimal::ToString()
{
	std::cout 
		<< "Dog name is -> " << this->name << std::endl
		<< "Dog heigth is -> " << this->heigth << std::endl
		<< "Dog weigth is -> " << this->weigth << std::endl;

}
