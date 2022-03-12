#include <iostream>

#include "Calculator.h"

int main()
{
	char expression[] = "5+5";
	Calculator myCalculator(expression);
	myCalculator.CalculateResult();
	std::cout << myCalculator.CalculateResult();
}
