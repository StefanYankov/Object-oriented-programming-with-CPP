#include "Handle.h"

Handle::Handle()
{
	diameter = 1;
	length = 5;
}
Handle::Handle(int diameter, int length)
{
	this->diameter = diameter;
	this->length = length;
}

int Handle::GetDiameter() const
{
	return diameter;
}
void Handle::SetDiameter(int diameter)
{
	this->diameter = diameter;
}

int Handle::GetLength() const
{
	return length;
}
void Handle::SetLength(int length)
{
	this->length = length;
}
