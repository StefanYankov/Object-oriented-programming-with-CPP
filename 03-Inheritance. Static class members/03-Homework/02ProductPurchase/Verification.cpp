#include "Verification.h"
#include "Purchase.h"
#include <iomanip>
#include <iostream>

void Verification::PurchaseVerification(Purchase purchase)
{

	for (int i = 0; i < purchase.GetRepositoryLengths(); i++)
	{
		std::cout << "Bough item :"
			<< purchase.GetNameRepository(i) << std::endl;
		std::cout << "at price:"
			<< std::fixed << std::setprecision(2) << purchase.GetPriceRepository(i) << std::endl;
	}
	std::cout 
		<< "Count of products bough: " << purchase.GetCountOfPurchasedProducts() << std::endl
		<< "Total weigth: " << purchase.GetTotalWeigthOfPurchasedProducts() << std::endl;
}
