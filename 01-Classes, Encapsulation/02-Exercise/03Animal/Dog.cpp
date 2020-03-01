#include "Dog.h"
#include <iostream>

Dog::Dog(std::string name, double heigth, double weigth, std::string sound) : CAnimal(name, heigth, weigth)
{
	this->sound = sound;
}

void Dog::ToString()
{
	std::cout
		<< "Dog name is -> " << GetName() << std::endl
		<< "Dog heigth is -> " << GetHeigth() << std::endl
		<< "Dog weigth is -> " << GetWeigth() << std::endl
		<< "Dog sound is -> " << this->sound << std::endl;
}