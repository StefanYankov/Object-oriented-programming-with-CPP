#include "Head.h"
#include "Element.h"
#include "Snake.h"
#include <iostream>

Element::Element()
{
	this->type = '*';
}

Element::Element(char type)
{
	this->SetType(type);
}

char Element::GetType() const
{
	return type;
}

void Element::SetType(char type)
{
	if (!isspace(type)) // check if the symbol is not a whitespace;
	{
		this->type = type;
	}
	else
	{
		std::cout << "Symbol cannot be a white space";
		this->SetType(type);
	}
}
