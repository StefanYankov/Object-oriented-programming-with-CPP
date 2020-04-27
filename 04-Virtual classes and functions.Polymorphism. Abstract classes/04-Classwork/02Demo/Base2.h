#pragma once
#include <iostream>
class Base2
{
private:
	int b2;
public:
	Base2(int b2 = 2) :b2(b2) { std::cout << "Base2 initialzed with " << b2 << std::endl; }
	friend std::ostream& operator<<(std::ostream& os, const Base2& ob);

};

