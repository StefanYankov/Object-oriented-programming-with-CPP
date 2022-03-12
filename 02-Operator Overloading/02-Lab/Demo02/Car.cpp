#include "Car.h"
#include <iostream>

constexpr int INCREMENT_VALUE = 100;
constexpr double PERCENT_MODIFIER_PER_YEAR = 10.0;
Car::Car()
{
	this->SetMade(new char[] {"default name"});
	this->SetDoors(4);
	this->SetHorsePower(125);
	this->SetYear(1990);
	this->SetPrice(350);
}

Car::Car(char* made, int doors, int horsePower, int year, double price)
{
	this->SetMade(made);
	this->SetDoors(doors);
	this->SetHorsePower(horsePower);
	this->SetYear(year);
	this->SetPrice(price);
}

Car::Car(const Car& other)
{
	this->SetMade(other.GetMade());
	this->SetDoors(other.GetDoors());
	this->SetHorsePower(other.GetHorsePower());
	this->SetYear(other.GetYear());
	this->SetPrice(other.GetPrice());
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		this->SetMade(other.GetMade());
		this->SetDoors(other.GetDoors());
		this->SetHorsePower(other.GetHorsePower());
		this->SetYear(other.GetYear());
		this->SetPrice(other.GetPrice());
	}
	return *this;
}

Car Car::operator+(const Car& other) const
{
	// Enter sum logic here

	Car temp(*this); 	// copy constructor
	//Car temp2(this->GetMade(),this->GetDoors(), this->GetHorsePower() + other.GetHorsePower(), this->GetYear(), this->GetPrice()); // constructor with params
	//return Car(this->GetMade(), this->GetDoors(), this->GetHorsePower() + other.GetHorsePower(), this->GetYear(), this->GetPrice()); // Anonymous object
	return temp;
}

Car Car::operator+(int number) const
{
	return Car(this->GetMade(), this->GetDoors(), this->GetHorsePower() + number, this->GetYear(), this->GetPrice());
}

Car& Car::operator+=(const Car& other)
{
	this->SetHorsePower(this->GetHorsePower() + other.GetHorsePower());

	//second option reusing existing predefined operators
	//*this = *this + other;

	return *this;
}

Car& Car::operator+=(const int other)
{
	*this = *this + other;
	return *this;
}

Car& Car::operator++()
{
	this->SetPrice(this->GetPrice() + INCREMENT_VALUE);
	// without getters and setters
	// this->horsePower++;
	return *this;
}

Car Car::operator++(int)
{
	Car temp = *this;
	this->SetPrice(this->GetPrice() + INCREMENT_VALUE);
	return temp;
}

Car& Car::operator--()
{
	this->SetPrice(this->GetPrice() - INCREMENT_VALUE);
	return *this;
}

Car Car::operator--(int)
{
	Car temp = *this;
	this->SetPrice(this->GetPrice() - INCREMENT_VALUE);
	return temp;
}

Car::operator int() const
{
	return this->GetHorsePower();
}

Car Car::operator%(const int years) const
{
	Car temp(*this);
	temp.SetPrice(temp.GetPrice() - temp.GetPrice() * (years * PERCENT_MODIFIER_PER_YEAR / 100));
	return temp;
}

bool Car::operator>(const Car& other) const
{
	if (this->GetPrice() > other.GetPrice())
	{
		return true;
	}

	if (this->GetPrice() == other.GetPrice() && this->GetYear() < other.GetYear())
	{
		return true;
	}
	return false;
}

bool Car::operator<(const Car& other) const
{
	return !(*this >= other);
}

bool Car::operator==(const Car& other) const
{
	bool output = (this->GetPrice() == other.GetPrice()
		&& this->GetDoors() == other.GetDoors()
		&& this->GetYear() == other.GetYear()
		&& this->GetHorsePower() == other.GetHorsePower()
		&& (strcmp(this->GetMade(), other.GetMade()) == 0));
	return output;

}

bool Car::operator>=(const Car& other) const
{
	return *this > other || *this == other;
}

bool Car::operator<=(const Car& other) const
{
	return !(*this > other);
}

Car::~Car()
{
	if (this->made != nullptr)
	{
		delete[] made;
	}
}

char* Car::GetMade() const
{
	return made;
}

void Car::SetMade(char* made)
{
	if (this->made != nullptr)
	{
		delete[] this->made;
	}

	this->made = new char[strlen(made) + 1];
	strcpy_s(this->made, strlen(made) + 1, made);
}

int Car::GetDoors() const
{
	return doors;
}

void Car::SetDoors(int doors)
{
	this->doors = doors;
}

int Car::GetHorsePower() const
{
	return horsePower;
}

void Car::SetHorsePower(int horsePower)
{
	this->horsePower = horsePower;
}

int Car::GetYear() const
{
	return year;
}

void Car::SetYear(int year)
{
	this->year = year;
}

double Car::GetPrice() const
{
	return price;
}

void Car::SetPrice(double price)
{
	this->price = price;
}

void Car::Print() const
{
	std::cout << "Made: " << this->GetMade() << std::endl;
	std::cout << "Doors: " << this->GetDoors() << std::endl;
	std::cout << "Horse Power: " << this->GetHorsePower() << std::endl;
	std::cout << "Year model: " << this->GetYear() << std::endl;
	std::cout << "Price: " << this->GetPrice() << std::endl;
}

std::ostream& Car::Inserter(std::ostream& out) const
{
	out << "Made: " << this->GetMade() << std::endl;
	out << "Doors: " << this->GetDoors() << std::endl;
	out << "Horse Power: " << this->GetHorsePower() << std::endl;
	out << "Year model: " << this->GetYear() << std::endl;
	out << "Price: " << this->GetPrice() << std::endl;

	return out;
}



std::ostream& operator<<(std::ostream& outputStream, const Car& car)
{
	return car.Inserter(outputStream);
}

Car operator+(int left, const Car& right)
{
	return left + right;
}
