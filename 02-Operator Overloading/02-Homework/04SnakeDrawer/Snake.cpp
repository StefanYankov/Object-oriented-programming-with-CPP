#include "Snake.h"
#include "Head.h"
#include "Element.h"
#include <iostream>

Snake::Snake()
	: Head()
{
	this->length = 6;
	this->wigth = 2;
}

Snake::Snake(char type, int size, int length, int width)
	: Head(type, size)
{
	this->SetLength(length);
	this->SetWigth(width);
}

int Snake::GetLength() const
{
	return this->length;
}

void Snake::SetLength(int length)
{
	if (length > 0)
	{
		this->length = length;
	}
	else
	{
		std::cout << "Body length needs to be greater than zero!";
	}
}

int Snake::GetWidth() const
{
	return this->wigth;
}

void Snake::SetWigth(int wigth)
{
	if (wigth > 0)
	{
		this->wigth = wigth;
	}
	else
	{
		std::cout << "The snake's width needs to be greater than zero!";
	}
}

void Snake::Print()
{
	Head::Print();
	int snakeWidth = this->GetWidth();
	int snakeLength = this->GetLength();
	int handleSpacing = (Head::GetSize() - 1) / 2;
	for (int i = 0; i < snakeLength; i++)
	{
		for (int j = 0; j < handleSpacing; j++)
		{
			std::cout << "  ";
		}
		for (int k = 0; k < snakeWidth; k++)
		{
			std::cout << Element::GetType();
		}
		std::cout << std::endl;
	}
}
