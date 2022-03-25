#include <iostream>

/*
 *  Create a Hoe class in C++:
 * - Add the option to change the head
 * - Add the option to change the length of the Hoe
 * - Add the option to print the hoe in console.
 */

#include "Hoe.h"

int main()
{
	char hoeElement = '=';
	int handleLength = 5;
	char * head = new char[] {"D"};
	Hoe myHoe(hoeElement, handleLength, head);

	std::cout << "Initial hoe" << std::endl;
	myHoe.Print();
	std::cout << std::endl;

	std::cout << "Post increment hoe" << std::endl;
	myHoe++;
	myHoe.Print();
	std::cout << std::endl;


	std::cout << "Pre-increment hoe" << std::endl;
	++myHoe;
	myHoe.Print();
	std::cout << std::endl;
}
