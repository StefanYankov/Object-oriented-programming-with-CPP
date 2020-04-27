#include "SweetBox.h"
#include <stdexcept>
#include "RoundSweet.h"
#include "SquareSweet.h"
#include "TriangularSweet.h"
#include <iostream>

SweetBox::SweetBox()
{
	int numberOfSweets = 3;
	Sweet** sweets;
	sweets = new Sweet * [numberOfSweets];

	sweets[0] = new RoundSweet();
	sweets[1] = new SquareSweet();
	sweets[2] = new TriangularSweet();
	
	this->SetWishes("my default wishes to you!");
	this->SetColourPallet("red");
}

SweetBox::SweetBox(Sweet** sweets, std::string wishes, std::string colourPallet)
{
	this->sweets = sweets;
	this->SetWishes(wishes);
	this->SetColourPallet(colourPallet);
}

SweetBox::SweetBox(const SweetBox& other)
{
	this->sweets = other.sweets;
	this->SetWishes(other.GetWishes());
	this->SetColourPallet(other.GetColourPallet());
}

SweetBox& SweetBox::operator=(const SweetBox& other)
{
	if (this != &other)
	{
		this->sweets = other.sweets;
		this->SetWishes(other.GetWishes());
		this->SetColourPallet(other.GetColourPallet());
	}
	return *this;
}

std::string SweetBox::GetWishes() const
{
	return this->wishes;
}

std::string SweetBox::GetColourPallet() const
{
	return this->colourPallet;
}


void SweetBox::SetWishes(std::string wishes)
{
	int wishesLength = wishes.length();
	if (wishesLength < 0 || wishesLength > 255)
	{
		throw std::invalid_argument("Wishes message must be between 1 and 255 characters long.");
	}
	this->wishes = wishes;
}

void SweetBox::SetColourPallet(std::string colour)
{
	bool isAvaliableColour = (colour == "black" || colour == "green" || colour == "red");
	if (!isAvaliableColour)
	{
		throw std::invalid_argument("Avaliable colours are black, green and red. Please pick one of those.");
	}
	this->colourPallet = colour;
}

void SweetBox::Print() const
{
	int arrayLength = sizeof(this) / sizeof(*this);
	for (int i = 0; i < arrayLength; ++i)
	{
		this->Print();
	}
	std::cout << this->GetWishes() << std::endl;
	std::cout << this->GetColourPallet() << std::endl;
}




