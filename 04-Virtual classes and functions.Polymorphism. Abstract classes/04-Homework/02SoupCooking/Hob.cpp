#include "Hob.h"
#include <stdexcept>
#include <iostream>

std::string Hob::GetSize() const
{
	return this->size;
}

void Hob::SetSize(std::string size)
{
	bool isCorrectSize = (size == "small" || size == "medium" || size == "large");
	if (!isCorrectSize)
	{
		throw std::invalid_argument("Hob size must be either small or medium or large.");
	}
	this->size = size;
}

Hob::Hob()
{
	this->SetSize("small");
	this->SetTimer(30);
	this->SetTemperature(90);
}

Hob::Hob(std::string size, int timer, int temperature)
{
	this->SetSize(size);
	this->SetTimer(timer);
	this->SetTemperature(temperature);
}

Hob::Hob(const Hob& other)
{
	this->SetSize(other.GetSize());
	this->SetTimer(other.GetTimer());
	this->SetTemperature(other.GetTemperature());;
}

Hob& Hob::operator=(const Hob& other)
{
	if (this != &other)
	{
		this->SetSize(other.GetSize());
		this->SetTimer(other.GetTimer());
		this->SetTemperature(other.GetTemperature());
	}
	return *this;
}

int Hob::GetTimer() const
{
	return this->timer;
}

void Hob::SetTimer(int timer)
{
	if (timer < 0)
	{
		throw std::invalid_argument("Timer must be a positive value");
	}
	else if (timer == 0)
	{
		std::cout << "Timer is now zero.Turning hob off.";
	}
	this->timer = timer;
}

int Hob::GetTemperature() const
{
	return this->temperature;
}

void Hob::SetTemperature(int temperature)
{
	if (temperature < 50)
	{
		throw std::invalid_argument("Temperature must be above 50 degrees, celsius");
	}
	else if (temperature > 250)
	{
		throw std::invalid_argument("Temperature below be below 250 degrees, celsius");
	}
	
	this->temperature = temperature;
}

void Hob::ReduceTimer()
{
	this->SetTimer(GetTimer() - 1);
}
