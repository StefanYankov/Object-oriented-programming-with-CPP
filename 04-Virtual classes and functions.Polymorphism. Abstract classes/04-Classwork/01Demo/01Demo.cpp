#include <iostream>
#include "Base.h"
#include "Derived.h"

int main()
{
	//downcast
	Base* ptr = new Derived(5, 5); // not losing data members of Derived
	if (ptr != nullptr)
	{
		delete ptr;
	}

	Base myBase;
	myBase.Print();
	Derived myDerived;
	myDerived.Print();
	//upcasting
	myBase = myDerived; //  losing data members of Derived
	myBase.Print();

	Base* arrBase[3];
	arrBase[0] = new Base;
	arrBase[1] = new Derived;
	arrBase[2] = new Derived(10, 20);
	if (dynamic_cast<Derived*>(arrBase[1]))
	{
		arrBase[1]->Print();
	}
	return 0;
}
