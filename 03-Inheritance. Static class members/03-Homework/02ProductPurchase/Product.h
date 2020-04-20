#pragma once
#include <string>
class Product
{
public:
	Product();
	Product(std::string, double, double);

	std::string GetName() const;
	void SetName(std::string);

	double GetPrice() const;
	void SetPrice(double);

	double GetWeigth() const;
	void SetWeigth(double);

	void Print();
private:
	std::string name;
	double price;
	double weigth;
};

