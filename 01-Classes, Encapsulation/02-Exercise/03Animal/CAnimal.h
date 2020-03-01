#pragma once
#include <string>
class CAnimal
{
public:
	CAnimal();
	CAnimal(std::string, double, double);

	std::string GetName() const;
	void SetName(std::string);

	double GetHeigth() const;
	void SetHeigth(double);

	double GetWeigth() const;
	void SetWeigth(double);

	void SetAll(std::string, double, double);
	static int GetNumberOfAnimals() { return numberOfAnimals; };
	void ToString();
private:
	std::string name;
	double heigth;
	double weigth;

	static int numberOfAnimals;
};

