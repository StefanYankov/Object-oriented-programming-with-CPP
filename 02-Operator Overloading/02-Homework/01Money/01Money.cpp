#include <iostream>
#include "Money.h"

int main()
{
	Money myMoney(10, 50);

	/* math operation tests
	Money myMoneySum(5, 55);
	Money outputSum(myMoney + myMoneySum);
	outputSum.Print();
	*/

	/* Comparison operators test

	Money myMoney2 = Money(10, 50);

	Money outputMoney(myMoney + myMoney2);
	std::cout << outputMoney;

	bool output = myMoney != myMoney2; // change operation
	if (output == 1)
	{
		std::cout << "True";
	}
	else
	{
		std::cout << "False";
	}
	*/

	/* n % m Percentage

	Money myMoneyPercentageN(5, 0);
	Money myMoneyPercentageM(100, 0);
	Money outputPercentage(myMoneyPercentageN % myMoneyPercentageM);
	outputPercentage.PrintPercentage();
	*/
}
