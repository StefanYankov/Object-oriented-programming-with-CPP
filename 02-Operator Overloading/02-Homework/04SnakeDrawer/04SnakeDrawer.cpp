#include <iostream>
#include "Snake.h"

int main()
{
	Snake mySnake('-', 6, 6, 2);
	std::cout << "My Snake looks like this:" << std::endl;
	mySnake.Print();

	Snake myDefSnake;
	std::cout << "A default Snake looks like this:" << std::endl;
	myDefSnake.Print();

	mySnake.SetLength(10);
	mySnake.SetType('0');
	std::cout << "My modified Snake looks like this:" << std::endl;
	mySnake.Print();

	return 0;
}
