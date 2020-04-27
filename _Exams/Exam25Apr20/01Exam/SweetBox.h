#pragma once
#include "Sweet.h"
class SweetBox :
	public Sweet
{
private:
	Sweet** sweets;
	std::string wishes;
	std::string colourPallet;
protected:
	void SetWishes(std::string);
	void SetColourPallet(std::string);
public:
	SweetBox();
	SweetBox(Sweet**, std::string, std::string);
	//~SweetBox(); no dynamic memory allocated;
	SweetBox(const SweetBox&);
	SweetBox& operator=(const SweetBox&);
	
	SweetBox& operator+(int); // logic to be added if small + 1 = medium, if medium + 1 = large, if large + 1 throw exception, we dont have bigger than Large. Vice versa for operator -
	SweetBox& operator-(int);
	SweetBox& operator+=(int);
	SweetBox& operator-=(int);
	
	std::string GetWishes() const;
	std::string GetColourPallet() const;

	void Print() const override;
};

