#include "Product.h"
#include <stdexcept>
#include <iostream>

int Product::count = 0;

Product::Product()
{
}

Product::Product(std::string name, std::string state, double quantity, std::string metricUnit, bool isCooked)
{
	this->SetName(name);
	this->SetState(state);
	this->SetQuantity(quantity);
	this->SetMetricUnit(metricUnit);
	this->SetIsCooked(isCooked);
	count++;
}

Product::~Product()
{
	// no dynamic memory hence only default destructor required;
	count--;
}

Product::Product(const Product& other)
{
	this->SetName(other.GetName());
	this->SetState(other.GetState());
	this->SetQuantity(other.GetQuantity());
	this->SetMetricUnit(other.GetMetricUnit());
	this->SetIsCooked(other.GetIsCooked());
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		this->SetName(other.GetName());
		this->SetState(other.GetState());
		this->SetQuantity(other.GetQuantity());
		this->SetMetricUnit(other.GetMetricUnit());
		this->SetIsCooked(other.GetIsCooked());
	}
	return *this;
}

std::string Product::GetName() const
{
	return this->name;
}

void Product::SetName(std::string name)
{
	if (name.length() == 0)
	{
		throw std::exception("Product name can't be blank.");
	}
	this->name = name;
}

std::string Product::GetState() const
{
	return this->state;
}


void Product::SetState(std::string state)
{

	if (state == "liquid" || state == "gas" || state == "solid")
	{
		this->state = state;
	}
	else
	{
		throw std::invalid_argument("State must be either liquid, solid or gas");
	}


}

double Product::GetQuantity() const
{
	return this->quantity;
}


void Product::SetQuantity(double quantity)
{
	if (quantity <= 0)
	{
		throw std::invalid_argument("Quantity cannot be a zero or negative value.");
	}
	
	this->quantity = quantity;

}

std::string Product::GetMetricUnit() const
{
	return this->metricUnit;
}

bool Product::GetIsCooked() const
{
	return this->isCooked;
}

void Product::SetMetricUnit(std::string metricUnit)
{
	if (metricUnit == "liters" || metricUnit == "gram" || metricUnit == "milliliters" || metricUnit== "milligrams")
	{
		this->metricUnit = metricUnit;
	}
	else
	{
		throw std::invalid_argument("Metric unit must be either liters, gram, milliliters or milligrams.");
	}

}

void Product::SetIsCooked(bool isCooked)
{
	this->isCooked = isCooked;
}

void Product::CookProduct()
{
	if (this->GetIsCooked() == true)
	{
		throw new std::exception("Product is already cooked.");
	}
	this->isCooked = true;
}


