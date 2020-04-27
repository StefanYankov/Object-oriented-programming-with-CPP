#pragma once
#include "Sweet.h"
class SquareSweet :
	public Sweet
{
private:
	std::string filling;
	std::string size;
protected:
	void SetSize(std::string);
	void SetFilling(std::string);
public:
	SquareSweet();
	SquareSweet(double, std::string, std::string, std::string);

	SquareSweet(const SquareSweet&);
	SquareSweet& operator=(const SquareSweet&);

	std::string GetFilling() const;
	std::string GetSize() const;

	void Print() const override;
};

