#include "SquareSweet.h"

#include <stdexcept>
#include <iostream>

SquareSweet::SquareSweet()
	: Sweet()
{
	this->SetFilling("berry");
	this->SetSize("small");
}

SquareSweet::SquareSweet(double cocoaPercent, std::string cocoaType, std::string filling, std::string size)
	: Sweet(cocoaPercent, cocoaType)
{
	this->SetFilling(filling);
	this->SetSize(size);
}

SquareSweet::SquareSweet(const SquareSweet& other)
	: Sweet(other)
{
	this->SetFilling(other.GetFilling());
	this->SetSize(other.GetSize());
}

SquareSweet& SquareSweet::operator=(const SquareSweet& other)
{
	Sweet::operator=(other);
	this->SetFilling(other.GetFilling());
	this->SetSize(other.GetSize());
	return *this;
}

std::string SquareSweet::GetSize() const
{
	return this->size;
}

void SquareSweet::SetSize(std::string size)
{
	bool isCorrectSize = (size == "small" || size == "medium" || size == "large");
	if (!isCorrectSize)
	{
		throw std::invalid_argument("Size of this sweet must be either small, medium or large");
	}
	this->size = size;
}

std::string SquareSweet::GetFilling() const
{
	return this->filling;
}
void SquareSweet::SetFilling(std::string filling)
{
	bool isAvaliableFilling = (filling == "berry" || filling == "rosehip" || filling == "apple" || filling == "hazelnut");
	if (!isAvaliableFilling)
	{
		throw std::invalid_argument("Filling must be one of berry, rosehip, apple or hazelnut.");
	}
	this->filling = filling;
}

void SquareSweet::Print() const
{
	std::cout << typeid(this).name() << std::endl;
	std::cout << this->GetCacaoPercent() << std::endl;
	std::cout << this->GetCacaoType() << std::endl;
	std::cout << this->GetFilling() << std::endl;
	std::cout << this->GetSize() << std::endl;
}