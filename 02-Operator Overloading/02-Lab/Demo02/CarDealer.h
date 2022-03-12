#pragma once
#include "Car.h"

class CarDealer
{
private:
	char* name{};
	int countOfCars{};
	Car* listOfCars{};
	bool IndexIsInRange(int index) const;
public:
	CarDealer();
	CarDealer(const  char* name, int countOfCars, Car* listOfCars);
	CarDealer(const CarDealer& other); // copy constructor
	// operator overloading
	CarDealer& operator=(const CarDealer& other);
	~CarDealer();

	char* GetName() const;
	void SetName(const char* name);

	int GetCountOfCars() const;
	void SetCountOfCars(int countOfCars);

	Car* GetListOfCars() const;
	void SetListOfCars(const Car* listOfCars);

	std::ostream& Inserter(std::ostream& out)const;

	Car operator[](int index) const; // called when called on a const object
	Car& operator[](int index);
	double operator()() const; // returns the sum of all cars in the list
	double operator()(int startingIndex, int endingIndex) const; // returns the sum of all cars in the list

};

std::ostream& operator<<(std::ostream& os, const CarDealer& carDealer);