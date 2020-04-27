#pragma once
#include "Base1.h"
#include "Base2.h"
#include "Derived1.h"

class Derived2 :public Base1, public Base2
{
	int d2;
public:
	Derived2(int b, int b2, int d) :Base1(b), Base2(b2), d2(d)
	{
		std::cout << "Deriv2 initialzed with " << d2 << std::endl;
	};
	friend std::ostream& operator<<(std::ostream& os, const Derived2& ob);
};

std::ostream& operator<<(std::ostream& os, const Base1& ob) { return os << " b1=" << ob.b1; }
std::ostream& operator<<(std::ostream& os, const Base2& ob) { return os << " b2=" << ob.b2; }
std::ostream& operator<<(std::ostream& os, const Derived1& ob) { return os << (Base1)ob << " d1=" << ob.d1; }
std::ostream& operator<<(std::ostream& os, const Derived2& ob) { return os << (Base1)ob << (Base2)ob << " d2=" << ob.d2; }
