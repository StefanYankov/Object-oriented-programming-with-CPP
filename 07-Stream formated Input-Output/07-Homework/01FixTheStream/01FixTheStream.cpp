#include <iostream>

int main()
{
	/*
	int x = 0;
	std::cout << "The value from 1 <= x <= 100 is :" << 1 << " <= " << x << " <= " << 100;
			*/
	int t;

	std::cout << '\t' << std::endl;


	bool b;
	std::cin >>b;
	if (std::cin.fail())
	{
		std::cerr << "bool can only be 0 or 1" << std::endl;
	}
	std::cout << b;

}
