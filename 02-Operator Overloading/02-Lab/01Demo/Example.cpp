#include "Example.h"
#include <iostream>

unsigned Example::count = 0;

Example::Example()
{
	this->a = 5;
	this->b = 6;
	this->length = 11;
	this->dynamicValue = new int[length];
	for (int i = 0; i < length; i++)
	{
		this->dynamicValue[i] = i;
	}
}

Example::Example(int a)
{
	this->a = a;
	this->b = 6;
	this->length = 11;
	this->dynamicValue = new int[length];
	for (int i = 0; i < length; i++)
	{
		this->dynamicValue[i] = i;
	}
}

Example::Example(int a, int b, unsigned length, int* dynamicValue)
{
	this->a = a;
	this->b = b;
	this->length = length;
	this->dynamicValue = new int[length];
	for (size_t i = 0; i < length; i++)
	{
		this->dynamicValue[i] = dynamicValue[i];
	}
}

Example::~Example()
{
	if (dynamicValue != nullptr)
	{
		delete[] dynamicValue;
		dynamicValue = nullptr;
	}
}

Example::Example(const Example& rhs)
{
	this->a = rhs.a;
	this->b = rhs.b;
	this->length = rhs.length;
	this->dynamicValue = new int[rhs.length];
	for (size_t i = 0; i < rhs.length; i++)
	{
		this->dynamicValue[i] = rhs.dynamicValue[i];
	}
}

int Example::GetA() const
{
	return this->a;
}

void Example::SetA(int a)
{
	this->a = a;
}

int Example::GetB() const
{
	return this->b;
}

void Example::SetB(int b)
{
	this->b = b;
}

int Example::GetDynamicValue(int i) const
{
	return dynamicValue[i];
}

void Example::SetDynamicValue(int* dynamicValue)
{
	this->dynamicValue = dynamicValue;
}

unsigned Example::GetLength() const
{
	return this->length;
}

void Example::SetLength(unsigned length)
{
	this->length = length;
}

unsigned Example::GetCount()
{
	return count;
}

void Example::Print() const
{
	cout << "a: " << GetA() << endl;
	cout << "b: " << GetB() << endl;
	cout << "length: " << GetLength() << endl;
	for (int i = 0; i < GetLength(); i++)
	{
		cout << this->dynamicValue[i] << '\t';

	}
	cout << endl;

}

Example& Example::operator=(const Example& rhs)
{
	if (this != &rhs)
	{
		this->a = rhs.a;
		this->b = rhs.b;
		if (dynamicValue != nullptr)
		{
			delete[] dynamicValue;
			dynamicValue = nullptr;
		}
		this->length = rhs.length;
		this->dynamicValue = new int[rhs.length];
		for (size_t i = 0; i < rhs.length; i++)
		{
			this->dynamicValue[i] = rhs.dynamicValue[i];
		}
	}
	return *this;
}

Example operator+(const Example& lhs, const Example& rhs)
{
	Example result;
	result.SetA(lhs.a + rhs.a);
	result.SetB(lhs.b + rhs.b);
	result.SetLength((lhs.GetLength() > rhs.GetLength()) ? lhs.GetLength() : rhs.GetLength());
	int smallerLength = (lhs.GetLength() < rhs.GetLength()) ? lhs.GetLength() : rhs.GetLength();
	for (int i = 0; i < result.GetLength(); i++)
	{
		if (i < smallerLength)
		{
			result.dynamicValue[i] = lhs.dynamicValue[i] + rhs.dynamicValue[i];
		}
		else
		{
			if (smallerLength < lhs.GetLength())
			{
				result.dynamicValue[i] = lhs.dynamicValue[i];
			}
			else
			{
				result.dynamicValue[i] = rhs.dynamicValue[i];
			}
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const Example& rhs)
{
	out << "a: " << rhs.GetA() << endl;
	out << "b: " << rhs.GetB() << endl;
	out << "length: " << rhs.GetLength() << endl;
	for (int i = 0; i < rhs.GetLength(); i++)
	{
		out << rhs.dynamicValue[i] << '\t';

	}
	out << endl;

	return out;
}

Example Example::operator-(const Example& rhs) const
{
	Example result;
	result.SetA(this->a - rhs.a);
	result.SetB(this->b - rhs.b);
	result.SetLength((this->GetLength() > rhs.GetLength()) ? this->GetLength() : rhs.GetLength());
	int smallerLength = (this->GetLength() < rhs.GetLength()) ? this->GetLength() : rhs.GetLength();
	for (int i = 0; i < result.GetLength(); i++)
	{
		if (i < smallerLength)
		{
			result.dynamicValue[i] = this->dynamicValue[i] + rhs.dynamicValue[i];
		}
		else
		{
			if (smallerLength < this->GetLength())
			{
				result.dynamicValue[i] = this->dynamicValue[i];
			}
			else
			{
				result.dynamicValue[i] = rhs.dynamicValue[i];
			}
		}
	}
	return result;
}

Example& Example::operator-=(const Example& rhs)
{
	//a = a - rhs.a; ...
	*this = *this - rhs;
	return *this;
}

Example::operator int() const
{
	return a;
}

