#include "Hoe.h"

#include <iostream>

constexpr int INCREMENT_VALUE = 1;

Hoe::Hoe()
{
	this->SetHandleEnd(new char[] { "|>" });
	this->SetHandleElement('=');
	this->SetHandleLength(3);
	this->SetHead(new char[] {'D'});
}

Hoe::Hoe(char handleElement, int handleLength, char* head)
{
	this->SetHandleEnd(new char[] { "|>" });
	this->SetHandleElement(handleElement);
	this->SetHandleLength(handleLength);
	this->SetHead(head);
}

Hoe::Hoe(const Hoe& other)
{
	this->SetHandleEnd(other.GetHandleEnd());
	this->SetHandleElement(other.GetHandleElement());
	this->SetHandleLength(other.GetHandleLength());
	this->SetHead(other.GetHead());
}

Hoe::~Hoe()
{
	if (this->handleEnd != nullptr) {
		delete[] handleEnd;
	}

	if (this->head != nullptr) {
		delete[] head;
	}
}

Hoe& Hoe::operator=(const Hoe& other)
{
	if (this != &other)
	{
		this->SetHandleEnd(other.GetHandleEnd());
		this->SetHandleElement(other.GetHandleElement());
		this->SetHandleLength(other.GetHandleLength());
		this->SetHead(other.GetHead());
	}

	return *this;
}

Hoe& Hoe::operator++()
{
	this->SetHandleLength(this->GetHandleLength() + INCREMENT_VALUE);
	return *this;
}

Hoe Hoe::operator++(int)
{
	Hoe temp = *this;
	this->SetHandleLength(this->GetHandleLength() + INCREMENT_VALUE);
	return temp;
}

Hoe& Hoe::operator--()
{
	this->SetHandleLength(this->GetHandleLength() - INCREMENT_VALUE);
	return *this;
}

Hoe Hoe::operator--(int)
{
	Hoe temp = *this;
	this->SetHandleLength(this->GetHandleLength() - INCREMENT_VALUE);
	return temp;
}

char* Hoe::GetHandleEnd() const
{
	return handleEnd;
}

void Hoe::SetHandleEnd(char* handleEnd)
{
	if (this->handleEnd != nullptr)
	{
		delete[] this->handleEnd;
	}

	this->handleEnd = new char[strlen(handleEnd) + 1];
	strcpy_s(this->handleEnd, strlen(handleEnd) + 1, handleEnd);
}

char Hoe::GetHandleElement() const
{
	return handleElement;
}

void Hoe::SetHandleElement(const char handleElement)
{
	this->handleElement = handleElement;
}

int Hoe::GetHandleLength() const
{
	return handleLength;
}

void Hoe::SetHandleLength(int handleLength)
{
	this->handleLength = handleLength;
}

char* Hoe::GetHead() const
{
	return head;
}

void Hoe::SetHead(char* const head)
{
	if (this->head != nullptr)
	{
		delete[] this->head;
	}

	this->head = new char[strlen(head) + 1];
	strcpy_s(this->head, strlen(head) + 1, head);
}

void Hoe::Print() const
{
	std::cout << this->GetHandleEnd();
	for (int i = 0; i < this->GetHandleLength(); ++i)
	{
		std::cout << this->GetHandleElement();
	}
	std::cout << this->GetHead();
}