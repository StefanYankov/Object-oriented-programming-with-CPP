#pragma once
#include "Base1.h"
class Derived1
	:public Base1
{
private:
	int d1;
public:
	Derived1(int b, int d)
		: Base1(b), d1(d)
	{
		std::cout << "Deriv1 initialzed with " << d1 << std::endl;
	};

	friend std::ostream& operator<<(std::ostream& os, const Derived1& ob);

};