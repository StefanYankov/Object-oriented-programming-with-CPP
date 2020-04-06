#include <iostream>
#include "Building.h"

int main()
{
	Building myBuilding("Rakovski str.",5,0,2,0);
	Building myBuiliding2("Stamboliyski blvd.", 3, 2, 3, 2);

	myBuilding.Print();

	(myBuilding + 5).Print();

	(5 + myBuilding).Print();

	std::cout << std::endl;
	std::cout << std::endl;

	myBuiliding2.Print();
	std::cout << std::endl;
	std::cout << std::endl;
	myBuiliding2 += 2;
	myBuiliding2.Print();
}
