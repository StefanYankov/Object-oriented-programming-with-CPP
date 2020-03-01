#pragma once
#include "CAnimal.h"
class Dog: public CAnimal
{
public:
	Dog() : CAnimal()
	{
	};
	Dog(std::string, double, double, std::string);
	void MakeSound();
	void ToString();

private:
	std::string sound = "Woof";
};

