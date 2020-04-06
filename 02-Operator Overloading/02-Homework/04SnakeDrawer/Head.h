#pragma once
#include "Element.h"
class Head
	: public Element
{
private:
	int size;
public:
	Head();
	Head(char, int);

	int GetSize() const;
	void SetSize(int);

	void Print() const;

};

