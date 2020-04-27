#include "Soup.h"
#include <stdexcept>
#include <iostream>

#include "Liquid.h"
#include "Vegetable.h"

Soup::Soup()
{
	this->SetType("vegetable");
	int numberOfProducts = 5;
	Product** products;
	products = new Product * [numberOfProducts];
	products[0] = new Vegetable("carrot", "solid", 120, "gram", false, true);
	products[1] = new Vegetable("potatoes", "solid", 200, "gram", false, true);
	products[2] = new Vegetable("green beans", "solid", 150, "gram", false, true);
	products[3] = new Liquid();

	CookingPot cookingPot;
	Hob hob;
}

Soup::Soup(std::string type, Product** products, CookingPot cookingPot, Hob hob)
{

	this->SetType(type);
	this->products = products;
	this->cookingPot = cookingPot;
	this->hob = hob;
}	

Soup::Soup(const Soup& other)
{
	this->SetType(other.GetType());
	this->products = other.products;
	this->cookingPot = other.cookingPot;
	this->hob = other.hob;
}

Soup& Soup::operator=(const Soup& other)
{
	if (this != &other)
	{
		this->SetType(other.GetType());
		this->products = other.products;
		this->cookingPot = other.cookingPot;
		this->hob = other.hob;
	}
	return *this;
}

std::string Soup::GetType() const
{
	return this->type;
}

void Soup::SetType(std::string type)
{
	bool isInListOfPossibleSoups = (type == "vegetable" || type == "meatballs" || type == "meat" || type == "creme");
	if (!isInListOfPossibleSoups)
	{
		throw std::invalid_argument("Known soups are only vegetable, meatballs, meat or creme.");
	}
	this->type = type;
}

void Soup::PrepareSoup()
{
	std::cout << this->GetType() << " soup is now prepared." << std::endl;
	std::cout << "Ingredients: " << std::endl;
	for (int i = 0; i < Product::GetCount(); i++)
	{
		products[i]->GetName();
	}
}
