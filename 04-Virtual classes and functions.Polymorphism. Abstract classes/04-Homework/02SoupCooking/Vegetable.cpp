#include "Vegetable.h"
#include <stdexcept>
#include <iostream>


Vegetable::Vegetable()
	: Product()
{
	this->SetIsSliced(false);
}

Vegetable::Vegetable(std::string name, std::string state, double quantity, std::string metricUnit, bool isCooked, bool isSliced)
	: Product(name, state, quantity, metricUnit, isCooked)
{
	this->SetIsSliced(isSliced);
}

Vegetable::Vegetable(const Vegetable& other)
	: Product(other)
{
	this->SetIsSliced(other.GetIsSliced());
}

Vegetable& Vegetable::operator=(const Vegetable& other)
{
	Product::operator=(other);
	this->SetIsSliced(other.GetIsSliced());
	return *this;
}

bool Vegetable::GetIsSliced() const
{
	return this->isSliced;
}

void Vegetable::SetIsSliced(bool isSliced)
{
	this->isSliced = isSliced;
}

void Vegetable::Slice()
{
	if (isSliced == true)
	{
		throw std::invalid_argument("Vegetable is already sliced.");
	}
	this->isSliced = true;
}

void Vegetable::Print() const
{
	std::cout << this->GetName() << std::endl;
	std::cout << this->GetState() << std::endl;
	std::cout << this->GetQuantity() << std::endl;
	std::cout << this->GetMetricUnit() << std::endl;
	std::cout << this->GetIsCooked() << std::endl;
	std::cout << this->GetIsSliced() << std::endl;
}

