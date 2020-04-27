#pragma once
#include "Base.h"
class Derived : public Base
{
public:
	Derived();
	Derived(int, int);
	~Derived();

	int GetDerived() const;
	void SetDerived(int);

	void Print() const;
private:
	int derived;
};

