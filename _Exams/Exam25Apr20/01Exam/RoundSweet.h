#pragma once
#include "Sweet.h"

class RoundSweet
	: public Sweet
{
private:
	std::string filling;
	std::string size;
protected:
	void SetSize(std::string);
	void SetFilling(std::string);
public:
	RoundSweet();
	RoundSweet(double, std::string, std::string, std::string);
	
	RoundSweet(const RoundSweet&);
	RoundSweet& operator=(const RoundSweet&);
	
	std::string GetFilling() const;
	std::string GetSize() const;

	void Print() const override;
};

