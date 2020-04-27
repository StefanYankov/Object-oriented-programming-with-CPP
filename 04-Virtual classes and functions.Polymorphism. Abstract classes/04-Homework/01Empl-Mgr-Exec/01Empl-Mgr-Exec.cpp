#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "Executive.h"

int main()
{
	try
	{
		Employee myEmployee;
		//myEmployee.Print();

		Employee myEmployee2("Stefan Y", 2500, 2, 13);
		//myEmployee2.PrintAll();

		Manager myManager;
		//myManager.Print();

		Manager myManager2("Serafim Gerasimoff", 9800, 10, 4, "Business intelligence");
		//myManager2.Print();

		Executive myExecutive;
		//myExecutive.Print();

		Executive myExecutive2("Gatso Batsoff", 20000, 5, 11, "Corporate");
		myExecutive2.Print();
	}
	catch (const std::exception & ex)
	{
		std::cerr << ex.what();
		return EXIT_FAILURE;
	}
	return 0;
}
