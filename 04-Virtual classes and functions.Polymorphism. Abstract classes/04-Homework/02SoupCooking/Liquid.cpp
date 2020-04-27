#include "Liquid.h"
#include <iostream>

Liquid::Liquid()
{
	this->SetName("water");
	this->SetState("liquid");
	this->SetQuantity(500);
	this->SetMetricUnit("milliliters");
	this->SetIsCooked(false);
}

Liquid::Liquid(std::string name, std::string state, double quantity, std::string metricUnit, bool isCooked)
	: Product(name, state, quantity, metricUnit, isCooked)
{

}

Liquid::Liquid(const Liquid& other)
{
	Product::operator=(other);
}

Liquid& Liquid::operator=(const Liquid& other)
{
	Product::operator=(other);
	return *this;
}

void Liquid::Print() const
{
	std::cout << this->GetName() << std::endl;
	std::cout << this->GetState() << std::endl;
	std::cout << this->GetQuantity() << std::endl;
	std::cout << this->GetMetricUnit() << std::endl;
	std::cout << this->GetIsCooked() << std::endl;
}
