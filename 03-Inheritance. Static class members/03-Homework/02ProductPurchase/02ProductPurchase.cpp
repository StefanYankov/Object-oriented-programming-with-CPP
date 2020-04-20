#include <iostream>
#include "Product.h"
#include "Purchase.h"
#include "Verification.h"
int main()
{
	try
	{
		Product myProduct("Banana", 5, 5);
		Product myProduct2("apple", 5, 5);
		Purchase myPurchase(myProduct);
		myPurchase.BuyProduct(myProduct2);

		Verification::PurchaseVerification(myPurchase);
	}
	catch(const std::exception& ex)
	{
		std::cerr << ex.what();
		return EXIT_FAILURE;
	}

	return 0;
}
