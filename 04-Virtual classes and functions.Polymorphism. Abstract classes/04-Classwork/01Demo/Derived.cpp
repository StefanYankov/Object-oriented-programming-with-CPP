#include "Derived.h"
#include <iostream>

Derived::Derived()
	: Base()
{
	this->derived = 0;
	this->Print();
}

Derived::Derived(int base, int derived)
	: Base(base)
{
	this->SetDerived(derived);
	this->Print();
}

Derived::~Derived()
{
	std::cout << "Derived destructor called!" << std::endl;
}

int Derived::GetDerived() const
{
	return this->derived;
}

void Derived::SetDerived(int derived)
{
	this->derived = derived;
}

void Derived::Print() const
{
	Base::Print();
	std::cout << "Derived object: " << std::endl
		<< "Derived = " << GetDerived() << std::endl;
}
