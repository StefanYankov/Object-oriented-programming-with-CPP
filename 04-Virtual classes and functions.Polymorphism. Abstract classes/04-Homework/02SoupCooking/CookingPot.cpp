#include "CookingPot.h"
#include <stdexcept>

/*
 * 	const int capacitySmall = 5;
	const int capacityMedium = 15;
	const int capacityLarge = 25;
 */

CookingPot::CookingPot()
{
	this->SetSize("small");
}

CookingPot::CookingPot(std::string size)
{
	this->SetSize(size);
}

CookingPot::CookingPot(const CookingPot& other)
{
	this->SetSize(other.GetSize());
}

CookingPot& CookingPot::operator=(const CookingPot& other)
{
	if (this != &other)
	{
		this->SetSize(other.GetSize());

	}
	return *this;
}

std::string CookingPot::GetSize() const
{
	return this->size;
}

void CookingPot::SetSize(std::string size)
{
	bool isCorrectSize = (size == "small" || size == "medium" || size == "large");
	if (!isCorrectSize)
	{
		throw std::invalid_argument("Cooking pot size must be either small or medium or large.");
	}
	this->size = size;
}
