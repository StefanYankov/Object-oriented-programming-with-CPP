#pragma once
#include <string>

class Sweet // abstract
{
private:
	double cocoaPercent;
	std::string cocoaType; // Forastero, Criollo, and Trinitario
protected:
	Sweet();
	Sweet(double, std::string);
	virtual ~Sweet();
	Sweet(const Sweet&);
	Sweet& operator=(const Sweet&);
	
	void SetCacaoPercent(double);
	void SetCacaoType(std::string);
public:
	double GetCacaoPercent() const;
	std::string GetCacaoType() const;
	
	virtual void Print() const = 0;
};
