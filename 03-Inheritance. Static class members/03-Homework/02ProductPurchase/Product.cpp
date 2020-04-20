#include "Product.h"
#include <iostream>

Product::Product()
{
	this->name = "default product";
	this->price = 0.1;
	this->weigth = 0.1;
}

Product::Product(std::string name, double price, double weigth)
{
	this->SetName(name);
	this->SetPrice(price);
	this->SetWeigth(weigth);
}

std::string Product::GetName() const
{
	return this->name;
}

void Product::SetName(std::string name)
{
	if (name.length() > 0)
	{
		this->name = name;
	}
	else
	{
		throw std::exception("Name cannot be empty");

	}
}

double Product::GetPrice() const
{
	return this->price;
}

void Product::SetPrice(double price)
{
	if (price > 0)
	{
		this->price = price;
	}
	else
	{
		throw std::exception("Price cannot be a negative or zero value.");
	}
}

double Product::GetWeigth() const
{
	return this->weigth;
}

void Product::SetWeigth(double weigth)
{
	if (weigth > 0)
	{
		this->weigth = weigth;
	}
	else
	{
		throw std::exception("Weigth cannot be a negative or zero value.");
	}
}

void Product::Print()
{
	std::cout << "Product name: " << this->GetName() << std::endl
		<< "Product price: " << this->GetPrice() << std::endl
		<< "Product weigth: " << this->GetWeigth() << std::endl
		<< std::endl;
}
