#pragma once
#include <ostream>
using namespace std;

class Money
{
public:
	Money();
	Money(int, int);
	Money(double);
	Money(const Money&);

	int GetBanknotes() const;
	void SetBanknotes(int);

	int GetCoins() const;
	void SetCoins(int);
	
	void Read();
	void Print() const;
	void PrintPercentage() const;
	void CoinsCalculation(int coins);

	Money& operator=(const Money&);
	bool operator>(const Money&)const;
	bool operator>=(const Money&)const;
	bool operator<(const Money&)const;
	bool operator<=(const Money&)const;
	bool operator==(const Money&)const;
	bool operator!=(const Money&)const;
	Money& operator++();
	Money operator++(int);
	Money& operator--();
	Money operator--(int);
	friend ostream& operator<<(ostream&, const Money&);
	friend istream& operator>>(istream&, const Money&);


private:
	int banknotes;
	int coins;
};

Money operator+(const Money&, const Money&);
Money operator-(const Money&, const Money&);
Money operator*(const Money&, const Money&);
Money operator/(const Money&, const Money&);
Money operator%(const Money&, const Money&);






