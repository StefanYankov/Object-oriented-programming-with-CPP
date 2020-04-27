#pragma once
#include <iostream>
class Base1
{
private:
	int b1;
public:
	Base1(int b1 = 1) :b1(b1) { std::cout << "Base1 initialzed with " << b1 << std::endl; }
	friend std::ostream& operator<<(std::ostream& os, const Base1& ob);
};

