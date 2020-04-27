#pragma once
#include <xstring>

class Product
{
private:
	std::string name; //
	std::string state;
	double quantity;
	std::string metricUnit;
	bool isCooked; // either pre-cooked for solid or boiled for liquids
	static int count;
protected:
	Product(); // default ctor
	Product(std::string, std::string, double, std::string, bool); // ctor
	virtual ~Product(); // destructor
	Product(const Product&); // copy ctor
	Product& operator=(const Product&); // assignment operator

	void SetName(std::string);
	void SetState(std::string);
	void SetQuantity(double);
	void SetMetricUnit(std::string);
	void SetIsCooked(bool);
	
	virtual void Print() const = 0; // so we have an abstract base class
public:
	std::string GetName() const;
	std::string GetState() const;
	double GetQuantity() const;
	std::string GetMetricUnit() const;
	bool GetIsCooked() const;
	void CookProduct();

	static int GetCount() { return count; };
};

