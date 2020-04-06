#include "Head.h"
#include "Element.h"
#include <iostream>

Head::Head() : Element()
{
	this->size = 5;
}

Head::Head(char type, int size) : Element(type)
{
	this->SetSize(size);
}

int Head::GetSize() const
{
	return this->size;
}

void Head::SetSize(int size)
{
	if (size > 0)
	{
		this->size = size;
	}
	else
	{
		std::cout << "The Snake must have a head. Please enter a value above 0";
		this->SetSize(size);
	}

}

void Head::Print() const
{
	char printType = Element::GetType();
	int headRows = this->GetSize();
	for (int i = 1; i <= headRows; i++)
	{
		for (int j = headRows - 1; j >= i; j--)
		{
			std::cout << " ";
		}
		for (int k = 1; k <= (2 * i - 1); k++)
		{
			std::cout << printType;
		}
		std::cout << std::endl;
	}
}
