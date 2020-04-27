#include "Sweet.h"
#include <stdexcept>


Sweet::Sweet()
{
	this->SetCacaoPercent(60);
	this->SetCacaoType("Default");
}

Sweet::Sweet(double cocoaPercent, std::string cocoaType)
{
	this->SetCacaoPercent(cocoaPercent);
	this->SetCacaoType(cocoaType);
}

Sweet::~Sweet()
{
	// no dynamic memory hence only default destructor required;
}

Sweet::Sweet(const Sweet& other)
{
	this->SetCacaoPercent(other.GetCacaoPercent());
	this->SetCacaoType(other.GetCacaoType());
}

Sweet& Sweet::operator=(const Sweet& other)
{
	if (this != &other)
	{
		this->SetCacaoPercent(other.GetCacaoPercent());
		this->SetCacaoType(other.GetCacaoType());
	}
	return *this;
}

double Sweet::GetCacaoPercent() const
{
	return this->cocoaPercent;
}

void Sweet::SetCacaoPercent(double cocoaPercent)
{
	if (cocoaPercent < 0 || cocoaPercent > 100)
	{
		throw std::invalid_argument("Cocoa percentage must be between 0 and 100 %");
	}
	this->cocoaPercent = cocoaPercent;
}

std::string Sweet::GetCacaoType() const
{
	return this->cocoaType;
}

void Sweet::SetCacaoType(std::string cocoaType) // Forastero, Criollo, and Trinitario
{
	bool isCorrectCocoa = (cocoaType == "Forastero" || cocoaType == "Criollo" || cocoaType == "Trinitario" || cocoaType == "Default");
	if (!isCorrectCocoa)
	{
		throw std::invalid_argument("Cocoa type must be one of either Forastero, Criollo, or Trinitario");
	}
	this->cocoaType = cocoaType;
}




