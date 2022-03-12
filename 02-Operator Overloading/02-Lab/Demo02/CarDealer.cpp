#include "CarDealer.h"


bool CarDealer::IndexIsInRange(int index) const
{
	if (index < 0 || index >= this->GetCountOfCars())
	{
		return false;
	}
	return true;
}

CarDealer::CarDealer()
{
	this->SetName(new char[] {"default name"});
	this->SetCountOfCars(0);
	this->SetListOfCars(nullptr);
}

CarDealer::CarDealer(const char* name, const int countOfCars, Car* listOfCars)
{
	this->SetName(name);
	this->SetCountOfCars(countOfCars);
	this->SetListOfCars(listOfCars);
}

CarDealer::CarDealer(const CarDealer& other)
{
	this->SetName(other.GetName());
	this->SetCountOfCars(other.GetCountOfCars());
	this->SetListOfCars(other.GetListOfCars());
}

CarDealer& CarDealer::operator=(const CarDealer& other)
{
	if (this != &other)
	{
		this->SetName(other.GetName());
		this->SetCountOfCars(other.GetCountOfCars());
		this->SetListOfCars(other.GetListOfCars());
	}
	return *this;
}

CarDealer::~CarDealer()
{
	if (this->name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
	if (listOfCars != nullptr)
	{
		delete[] listOfCars;
		listOfCars = nullptr;
	}
}

char* CarDealer::GetName() const
{
	return name;
}

void CarDealer::SetName(const char* name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

int CarDealer::GetCountOfCars() const
{
	return countOfCars;
}

void CarDealer::SetCountOfCars(int countOfCars)
{
	this->countOfCars = countOfCars;
}

Car* CarDealer::GetListOfCars() const
{
	return listOfCars;
}

void CarDealer::SetListOfCars(const Car* listOfCars)
{
	this->listOfCars = new Car[this->GetCountOfCars()];
	for (int i = 0; i < this->GetCountOfCars(); i++)
	{
		this->listOfCars[i] = listOfCars[i];
	}
}

std::ostream& CarDealer::Inserter(std::ostream& out) const
{
	out << "Dealer name: " << this->GetName() << std::endl;
	out << "Number for cars: " << this->GetCountOfCars() << std::endl;
	out << "Cars: " << std::endl;
	for (int i = 0; i < this->GetCountOfCars(); ++i)
	{
		out << "-- Car[" << i + 1 << "]: " << listOfCars[i] << std::endl;
	}
	return out;
}

Car CarDealer::operator[](int index) const
{
	if (!IndexIsInRange(index))
	{
		throw std::out_of_range("index is out of range");
	}
	return listOfCars[index];
}

Car& CarDealer::operator[](int index)
{
	if (!IndexIsInRange(index))
	{
		throw std::out_of_range("index is out of range");
	}
	return listOfCars[index];
}

double CarDealer::operator()() const
{
	return this->operator()(0, this->GetCountOfCars()-1);
}

double CarDealer::operator()(int startingIndex, int endingIndex) const
{
	double sum = 0.0;

	if (!(IndexIsInRange(startingIndex) && IndexIsInRange(endingIndex)))
	{
		throw std::out_of_range("index is out of range");
	}

	for (int i = startingIndex; i <= endingIndex; ++i)
	{
		sum += this->GetListOfCars()[i].GetPrice();
	}
	return sum;
}


std::ostream& operator<<(std::ostream& os, const CarDealer& carDealer)
{
	return carDealer.Inserter(os);
}
