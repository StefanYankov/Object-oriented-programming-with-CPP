#include "RoundSweet.h"
#include <stdexcept>
#include <iostream>


RoundSweet::RoundSweet()
	: Sweet()
{
	this->SetFilling("berry");
	this->SetSize("small");
}

RoundSweet::RoundSweet(double cocoaPercent, std::string cocoaType, std::string filling, std::string size)
	: Sweet(cocoaPercent, cocoaType)
{
	this->SetFilling(filling);
	this->SetSize(size);
}

RoundSweet::RoundSweet(const RoundSweet& other)
	: Sweet(other)
{
	this->SetFilling(other.GetFilling());
	this->SetSize(other.GetSize());
}

RoundSweet& RoundSweet::operator=(const RoundSweet& other)
{
	Sweet::operator=(other);
	this->SetFilling(other.GetFilling());
	this->SetSize(other.GetSize());
	return *this;
}

std::string RoundSweet::GetSize() const
{
	return this->size;
}

void RoundSweet::SetSize(std::string size)
{
	bool isCorrectSize = (size == "small" || size == "medium" || size == "large");
	if (!isCorrectSize)
	{
		throw std::invalid_argument("Size of this sweet must be either small, medium or large");
	}
	this->size = size;
}

std::string RoundSweet::GetFilling() const
{
	return this->filling;
}
void RoundSweet::SetFilling(std::string filling)
{
	bool isAvaliableFilling = (filling == "berry" || filling == "rosehip" || filling == "apple" || filling == "hazelnut");
	if (!isAvaliableFilling)
	{
		throw std::invalid_argument("Filling must be one of berry, rosehip, apple or hazelnut.");
	}
	this->filling = filling;
}

void RoundSweet::Print() const
{
	std::cout << typeid(this).name() << std::endl;
	std::cout << this->GetCacaoPercent() << std::endl;
	std::cout << this->GetCacaoType() << std::endl;
	std::cout << this->GetFilling() << std::endl;
	std::cout << this->GetSize() << std::endl;
}