#include "Base.h"
#include <iostream>

Base::Base()
{
	base = 0;
}

Base::Base(int base)
{
	this->SetBase(base);
}

Base::~Base()
{
	std::cout << "Base destrurctor called!" << std::endl;
}

int Base::GetBase() const
{
	return this->base;
}

void Base::SetBase(int base)
{
	this->base = base;
}

void Base::Print() const
{
	std::cout << "Base object: " << std::endl
		<< "Base = " << GetBase() << std::endl;
}
