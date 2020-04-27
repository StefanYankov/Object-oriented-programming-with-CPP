#pragma once
#include <string>

class CookingPot
{
private:
	std::string size;
	/* TO BE IMPLEMENTED if pot can contain all of the products.
	const int capacitySmall = 5;
	const int capacityMedium = 15;
	const int capacityLarge = 25;
	*/
	
protected:
	void SetSize(std::string);
public:
	CookingPot();
	CookingPot(std::string);
	//~CookingPot(); no dynamic memory, hence using the default destructor
	CookingPot(const CookingPot&);
	CookingPot& operator=(const CookingPot&);
	
	std::string GetSize() const;
};

