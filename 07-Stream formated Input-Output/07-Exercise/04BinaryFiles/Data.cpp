#include "Data.h"

Data::Data(double myDouble, int myInteger)
{
	this->myDouble = myDouble;
	this->myInteger = myInteger;
}

std::ostream& Data::inserter(std::ostream& out) const
{
	return out << "myDouble = " << myDouble << std::endl << "myInteger = " << myInteger << std::endl;
}

std::ostream& operator<<(std::ostream& lhs, const Data& rhs)
{
	return rhs.inserter(lhs);
}
