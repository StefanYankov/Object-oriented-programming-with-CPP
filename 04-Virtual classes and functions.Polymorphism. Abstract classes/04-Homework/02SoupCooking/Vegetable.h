#pragma once
#include "Product.h"

class Vegetable
	: public Product
{
private:
	bool isSliced;
protected:
	void SetIsSliced(bool);
public:
	Vegetable();
	Vegetable(std::string, std::string, double, std::string, bool, bool);
	Vegetable(const Vegetable&); // copy ctor
	Vegetable& operator=(const Vegetable&); // assignment operator
	
	bool GetIsSliced() const;
	void Slice();
	void Print() const override;
};

