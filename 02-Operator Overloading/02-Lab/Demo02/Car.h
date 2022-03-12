#pragma once
#include <ostream>

class Car
{
private:
	char* made{};
	int doors{};
	int horsePower{};
	int year{};
	double price{};
public:
	Car();
	Car(char* made, int doors, int horsePower, int year, double price);
	Car(const Car& other); // copy constructor
	// operator overloading
	Car& operator=(const Car& other);

	Car operator+(const Car& other) const;
	Car operator+(int number) const; // sum car with in

	Car& operator+=(const Car& other);
	Car& operator+=(int other);

	Car& operator++(); // pre-fix increment operator overload
	Car operator++(int); // adding a dummy argument so we can distinguish from pre-fix

	Car& operator--();
	Car operator--(int);
	explicit operator int() const; // override int so class can be used in arithmetic operations with integers

	Car operator%(int years) const;

	bool operator>(const Car& other) const;
	bool operator<(const Car& other) const;
	bool operator==(const Car& other) const;
	bool operator>=(const Car& other) const;
	bool operator<=(const Car& other) const;

	// destructor
	~Car();

	char* GetMade() const;
	void SetMade(char* made);

	int GetDoors() const;
	void SetDoors(int doors);

	int GetHorsePower() const;
	void SetHorsePower(int horsePower);

	int GetYear() const;
	void SetYear(int year);

	double GetPrice() const;
	void SetPrice(double price);

	void Print() const;

	std::ostream& Inserter(std::ostream& out) const;

};

std::ostream& operator<<(std::ostream& os, const Car& car);
Car operator+(int left, const Car& right); // sum int with car