#pragma once
#include <string>

using namespace std;

class BigInteger
{
public:
	BigInteger();
	BigInteger(string);

	long long GetBigInteger() const;
	void SetBigInteger(string);

	void Read();
	void Print() const;

	BigInteger operator+(const BigInteger&);
	BigInteger operator-(const BigInteger&);
	BigInteger operator*(const BigInteger&);
	friend ostream& operator<<(ostream&, const BigInteger&);

private:
	long long int number;
};

