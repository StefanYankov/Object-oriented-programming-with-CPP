#pragma once
#include <ostream>

class Data
{
private:
	double myDouble;
	int myInteger;
public:
	Data(double = 0., int = 0);
	std::ostream& inserter(std::ostream&) const;
};

std::ostream& operator<<(std::ostream&, const Data&);

