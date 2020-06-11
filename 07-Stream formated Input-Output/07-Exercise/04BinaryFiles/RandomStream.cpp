#include "RandomStream.h"
#include <cstdlib>

int RandomStream::randomInteger()
{
	int temp = rand();
	return(temp % 2 == 0 ? temp : -temp);
}

double RandomStream::randomDouble()
{
	double tempDouble = rand();
	double temp = tempDouble / RAND_MAX;
	
	return temp *randomInteger() * 100.;
}

void RandomStream::randomString(char* inputString)
{
	// we can use:
	// an array with alphabet lower case 
	// 97-123, 32 -> using this
	// 'a' ... 'z'

	int random = 0;
	
	for (int i = 0; i < getStringLength() - 1; ++i)
	{
		random = rand() % (123 - 97 + 1) + 97;
		if (getHasWhiteSpace() == true && random == 123)
		{
			inputString[i] = ' ';
		} else
		{
			if(random == 123)
			{
				inputString[i] = (char)(random - 1);
			}
			else
			{
				inputString[i] = (char)random;
			}
		}
	}
	inputString[getStringLength() - 1] = '\0';
}

RandomStream::RandomStream(int stringLength, bool hasWhiteSpace)
{
	this->setStringLength(stringLength);
	this->setHasWhiteSpace(hasWhiteSpace);
}

int RandomStream::getStringLength() const
{
	return this->stringLength;
}

void RandomStream::setStringLength(int stringLength)
{
	this->stringLength = stringLength;
}

bool RandomStream::getHasWhiteSpace() const
{
	return this->hasWhiteSpace;
}

void RandomStream::setHasWhiteSpace(bool hasWhiteSpace)
{
	this->hasWhiteSpace = hasWhiteSpace;
}

RandomStream& RandomStream::operator>>(int& integer)
{
	integer = randomInteger();
	return *this;
}

RandomStream& RandomStream::operator>>(double& inputDouble)
{
	inputDouble = randomDouble();
	return *this;
}

RandomStream& RandomStream::operator>>(unsigned& unsignedInteger)
{
	unsignedInteger = rand();
	return *this;
}

RandomStream& RandomStream::operator>>(char* str)
{
	randomString(str);
	return *this;
}
