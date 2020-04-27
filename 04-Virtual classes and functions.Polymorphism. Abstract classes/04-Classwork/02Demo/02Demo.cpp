#include <iostream>
#include "Base1.h"
#include "Base2.h"
#include "Derived1.h"
#include "Derived2.h"

using namespace std;
int main()
{
	Base1 b;
	cout << "Base1 object " << b << endl;
	cout << "Size of Base1 object " << sizeof(b) << endl << endl;
	Base2 bb;
	cout << "Base2 object " << bb << endl;
	cout << "Size of Base2 object " << sizeof(bb) << endl << endl;
	Derived1 d(11, 22);
	cout << "Deriv1 object " << d << endl;
	cout << "Size of Deriv1 object " << sizeof(d) << endl << endl;
	Derived2 dd(10, 20, 30);
	cout << "Deriv2 object " << dd << endl;
	cout << "Size of Deriv2 object " << sizeof(dd) << endl << endl;
	cout << "Static upcast of Deriv2 to Base1:\n";
	b = dd;
	cout << "Base1 object contains " << b << endl << endl;
	cout << "Static upcast of Deriv2 to Base2:\n";
	bb = dd;
	cout << "Base2 object contains " << bb << endl;
	return 0;

}
