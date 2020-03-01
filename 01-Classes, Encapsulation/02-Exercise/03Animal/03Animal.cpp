#include <iostream>
#include "CAnimal.h"
#include "Dog.h"

int main()
{
	CAnimal fred;
	fred.ToString();

	std::cout << std::endl;

	fred.SetHeigth(33);
	fred.SetWeigth(33);
	fred.SetName("Fred");
	fred.ToString();

	std::cout << std::endl;

	CAnimal tom("Tom", 36, 15);
	tom.ToString();

	std::cout << std::endl;

	Dog spot("Spot", 38, 16, "Woooff");
	spot.ToString();

	std::cout << "Number of animals: " 
		<< CAnimal::GetNumberOfAnimals() << std::endl;

	return 0;
}
