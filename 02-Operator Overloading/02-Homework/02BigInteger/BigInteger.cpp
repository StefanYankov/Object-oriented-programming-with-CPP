#include "BigInteger.h"
#include <iostream>

BigInteger::BigInteger()
{
	number = 123456789;
}
BigInteger::BigInteger(string number)
{
	this->number = stoll(number);
}

long long BigInteger::GetBigInteger() const
{
	return number;
}
void BigInteger::SetBigInteger(string number)
{
	this->number = stoll(number);
}

void BigInteger::Read()
{

}
void BigInteger::Print() const
{
	std::cout << number;
}

BigInteger BigInteger::operator+(const BigInteger& r)
{
	return to_string(number + r.GetBigInteger());
}
BigInteger BigInteger::operator-(const BigInteger& r)
{
	return to_string(number - r.GetBigInteger());
}
BigInteger BigInteger::operator*(const BigInteger& r)
{
	return to_string(number * r.GetBigInteger());
}

ostream& operator<<(ostream& output, const BigInteger& bigInteger)
{
	output << bigInteger.number;

	return output;
}