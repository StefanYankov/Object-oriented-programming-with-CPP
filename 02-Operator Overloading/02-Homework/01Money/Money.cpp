#include "Money.h"
#include <iostream>
#include <cassert>

using namespace std;

Money::Money()
{
	banknotes = 0;
	coins = 0; 
}

Money::Money(int banknotes, int coins)
{
	if (banknotes < 0)
	{
		cout << "Levas cannot be smaller than 0." << endl;
	}
	else
	{
		this->banknotes = banknotes;
	}

	this->coins = 0; // initiallizing coins so we dont get a random number added to sum;
	if (coins >= 100)
	{
		SetCoins(coins);
	}
	else if (coins < 0)
	{
		cout << "Stotinki cannot be smaller than 0." << endl;
	}
	else
	{
		this->coins = coins;
	}

}

Money::Money(double percentage)
{
	banknotes = (int)(percentage / 100);
	coins = fmod(percentage, 100);
}

Money::Money(const Money& other)
{
	banknotes = other.banknotes;
	coins = other.coins;
}

int Money::GetBanknotes() const
{
	return banknotes;
}
void Money::SetBanknotes(int banknotes)
{
	this->banknotes = banknotes;
}

int Money::GetCoins() const
{
	return coins;
}
void Money::SetCoins(int coins)
{
	CoinsCalculation(coins);
}

void Money::CoinsCalculation(int coins)
{
	if (this->coins + coins >= 100)
	{
		int tempBanknotes = coins / 100;
		int tempCoins = coins % 100;
		SetBanknotes(this->banknotes + tempBanknotes);
		this->coins = this->coins + tempCoins;
	}
	else if (this->coins + coins <= 100)
	{
		int tempBanknotes = coins / 100;
		int tempCoins = coins % 100;
		if (this->banknotes - tempBanknotes >= 0)
		{
			SetBanknotes(this->banknotes - tempBanknotes);
		}
		else
		{
			cout << "You don't have enough money";
		}

		this->coins = tempCoins - this->coins;
	}
	else
	{
		this->coins = coins;
	}
}

void Money::Read()
{
	do {
		std::cout << "Enter the banknotes:";
		std::cin >> banknotes;
	} while (banknotes <= 0);

	do {
		std::cout << "Enter the denominator:";
		std::cin >> coins;
	} while (coins <= 0);

}

void Money::Print() const // to test calculations
{
	printf("You have %d levas and %d stotinki.", banknotes, coins);
}

void Money::PrintPercentage() const
{
	cout << "n % m is: " << banknotes << ".";
	if (coins < 10)
	{
		cout << "0";
	}
	cout << coins << "%" << endl;
}

Money& Money::operator=(const Money& money)
{
	if (this != &money) {
		banknotes = money.banknotes;
		coins = money.coins;
	}
	return *this;
}

Money operator+(const Money& r1, const Money& r2)
{
	return Money(r1.GetBanknotes() + r2.GetBanknotes(), r1.GetCoins() + r2.GetCoins());
}

Money& Money::operator++() // increases only levas with 1
{

	banknotes += 1;
	// coins += 1; can enable this also
	return *this;
}

Money Money::operator++(int) // increases only levas with 1
{
	Money temp = *this;
	banknotes += 1;
	// coins += 1; can enable this also
	return temp;
}

Money operator-(const Money& r1, const Money& r2)
{

	return Money(r1.GetBanknotes() - r2.GetBanknotes(), r1.GetCoins() - r2.GetCoins());
}

Money& Money::operator--() // decreases only levas with 1
{

	banknotes -= 1;
	// coins -= 1; can enable this also
	return *this;
}

Money Money::operator--(int) // decreases only levas with 1
{
	Money temp = *this;
	banknotes -= 1;
	// coins -= 1; can enable this also
	return temp;
}

bool Money::operator>(const Money& l)const
{
	if (banknotes > l.banknotes)
	{
		return true;
	}
	else if (banknotes == l.banknotes)
	{
		if (coins > l.coins)
		{
			return true;
		}
		return false;
	}
	return false;
}

bool Money::operator>=(const Money& l)const
{
	if (banknotes >= l.banknotes)
	{
		if (coins >= l.coins)
		{
			return true;
		}
		return false;
	}
	return false;
}

bool Money::operator<(const Money& l)const
{
	if (banknotes < l.banknotes)
	{
		return true;
	}
	else if (banknotes == l.banknotes)
	{
		if (coins < l.coins)
		{
			return true;
		}
		return false;
	}
	return false;
}

bool Money::operator<=(const Money& l)const
{
	if (banknotes <= l.banknotes)
	{
		if (coins <= l.coins)
		{
			return true;
		}
		return false;
	}
	return false;
}

bool Money::operator==(const Money& l)const
{
	if (banknotes == l.banknotes)
	{
		if (coins == l.coins)
		{
			return true;
		}
		return false;
	}
	return false;
}

bool Money::operator!=(const Money& l)const
{
	if (banknotes != l.banknotes)
	{
		if (coins != l.coins)
		{
			return true;
		}
		return false;
	}
	return false;
}

ostream& operator<<(ostream& output, const Money& money)
{
	//You have %d levas and %d stotinki.
	output << "You have " << money.GetBanknotes() << "levas and " << money.GetCoins() << "stotinki." << endl;

	return output;
	// or just call Print()
}

istream& operator>>(istream& in, Money& money)
{
	int tempBanknote = 0;
	int tempCoin = 0;
	in >> tempBanknote;
	char decimalPoint;
	in >> decimalPoint;
	if (decimalPoint == '.')
	{
		in >> tempCoin;
	}
	else
	{
		cin.unget();
		tempCoin = 1;
	}
	money = Money(tempBanknote, tempCoin);
	return in;
}

Money operator*(const Money& r1, const Money& r2) // gives an approximate value as we are using integers in this example. We need a float/double to get a proper calculation of the multiplication,
												  // but we cannot use % for float/double numbers, to properly calculate the coins when they exceed 100, and cannot find another way to get that
{
	return Money(r1.GetBanknotes() * r2.GetBanknotes(), r1.GetCoins() * r2.GetCoins());
}

Money operator/(const Money& r1, const Money& r2) // gives an approximate value as we are using integers in this example, as with each operation we lose the floating point number
{
	assert(r2.GetBanknotes() != 0); // divide by 0 check
	assert(r2.GetCoins() != 0); // divide by 0 check
	return Money(r1.GetBanknotes() / r2.GetBanknotes(), r1.GetCoins() / r2.GetCoins());
}

Money operator%(const Money& r1, const Money& r2)
{
	double tempCoinsr1 = r1.GetCoins();
	double tempR1 = r1.GetBanknotes() + tempCoinsr1 * 0.01; // n %
	double tempCoinsr2 = r2.GetCoins();
	double tempR2 = r2.GetBanknotes() + tempCoinsr2 * 0.01; // m
	double percentage = tempR2 * tempR1 * 0.01;
	return percentage;
}