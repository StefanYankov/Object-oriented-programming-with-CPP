#pragma once
#include "Sweet.h"
class TriangularSweet :
	public Sweet
{
private:
	std::string filling;
	std::string size;
protected:
	void SetSize(std::string);
	void SetFilling(std::string);
public:
	TriangularSweet();
	TriangularSweet(double, std::string, std::string, std::string);

	TriangularSweet(const TriangularSweet&);
	TriangularSweet& operator=(const TriangularSweet&);

	std::string GetFilling() const;
	std::string GetSize() const;

	void Print() const override;
};

