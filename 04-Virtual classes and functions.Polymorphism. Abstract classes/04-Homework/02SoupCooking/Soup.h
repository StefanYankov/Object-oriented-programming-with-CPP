#pragma once
#include "Vegetable.h"
#include "CookingPot.h"
#include "Hob.h"

class Soup
: public Vegetable
{
private:
	std::string type;
	Product** products;
	CookingPot cookingPot;
	Hob hob;
protected:
	void SetType(std::string);
public:
	Soup();
	Soup(std::string, Product**, CookingPot, Hob);
	//~Soup(); no dynamic memory allocated;
	Soup(const Soup&);
	Soup& operator=(const Soup&);

	std::string GetType() const;
	
	void PrepareSoup();
};

