#include <iostream>
#include <string>

#include "Product.h"
#include "Vegetable.h"
#include "Soup.h"
#include "Liquid.h"

using namespace std;

int main()
{
	try
	{
	//default
	Soup myDefaultSoup;

	//myDefaultSoup.PrepareSoup(); unable to force the print function to print the product details

	// custom soup

		int numberOfProducts = 5;

		Product** products;
		products = new Product * [numberOfProducts];

		products[0] = new Vegetable("carrot", "solid", 120, "gram", false, true);
		products[1] = new Liquid("water", "liquid", 750, "milliliters", false); // change gram to grams to trigger exceptions
		products[2] = new Vegetable("potatoes", "solid", 250, "gram", false, true);
		products[3] = new Liquid("sunflower oil", "liquid", 10, "milliliters", false);
		products[4] = new Vegetable("onion", "solid", 100, "gram", true, true);


		CookingPot myDefaultCookingPot;
		Hob myDefaultHob;

		//Soup::Soup(std::string type, Product** products, CookingPot cookingPot, Hob hob)
		Soup myVegetableSoup("vegetable", products, myDefaultCookingPot, myDefaultHob);

		//myVegetableSoup.PrepareSoup(); unable to force the print function to print the product details
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}

	return 0;
}
