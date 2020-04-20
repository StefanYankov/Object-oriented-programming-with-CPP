#include <iostream>
#include "Employee.h"
#include "Programmer.h"

int main()
{
    Employee myEmployee;

    Programmer myProgrammer("Hacker, Harry", 3200.50);
    std::cout << myProgrammer.get_name();
}
