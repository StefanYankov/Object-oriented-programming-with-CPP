#pragma once
#include "Product.h"

class Liquid
: public Product
{
public:
	Liquid();
	Liquid(std::string, std::string, double, std::string, bool);
	Liquid(const Liquid&); // copy ctor
	Liquid& operator=(const Liquid&);

	void Print() const override;
};

