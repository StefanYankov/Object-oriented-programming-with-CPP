#include "TriangularSweet.h"
#include <stdexcept>
#include <iostream>

TriangularSweet::TriangularSweet()
	: Sweet()
{
	this->SetFilling("berry");
	this->SetSize("small");
}

TriangularSweet::TriangularSweet(double cocoaPercent, std::string cocoaType, std::string filling, std::string size)
	: Sweet(cocoaPercent, cocoaType)
{
	this->SetFilling(filling);
	this->SetSize(size);
}

TriangularSweet::TriangularSweet(const TriangularSweet& other)
	: Sweet(other)
{
	this->SetFilling(other.GetFilling());
	this->SetSize(other.GetSize());
}

TriangularSweet& TriangularSweet::operator=(const TriangularSweet& other)
{
	Sweet::operator=(other);
	this->SetFilling(other.GetFilling());
	this->SetSize(other.GetSize());
	return *this;
}

std::string TriangularSweet::GetSize() const
{
	return this->size;
}

void TriangularSweet::SetSize(std::string size)
{
	bool isCorrectSize = (size == "small" || size == "medium" || size == "large");
	if (!isCorrectSize)
	{
		throw std::invalid_argument("Size of this sweet must be either small, medium or large");
	}
	this->size = size;
}

std::string TriangularSweet::GetFilling() const
{
	return this->filling;
}
void TriangularSweet::SetFilling(std::string filling)
{
	bool isAvaliableFilling = (filling == "berry" || filling == "rosehip" || filling == "apple" || filling == "hazelnut");
	if (!isAvaliableFilling)
	{
		throw std::invalid_argument("Filling must be one of berry, rosehip, apple or hazelnut.");
	}
	this->filling = filling;
}

void TriangularSweet::Print() const
{
	std::cout << typeid(this).name() << std::endl;
	std::cout << this->GetCacaoPercent() << std::endl;
	std::cout << this->GetCacaoType() << std::endl;
	std::cout << this->GetFilling() << std::endl;
	std::cout << this->GetSize() << std::endl;
}