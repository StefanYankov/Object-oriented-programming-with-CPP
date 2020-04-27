#include <iostream>
#include "RoundSweet.h"
#include "SweetBox.h"
#include "SquareSweet.h"
#include "TriangularSweet.h"

int main()
{

	
	try
	{
		int numberOfSweets = 3;
		Sweet** mySweets;
		mySweets = new Sweet * [numberOfSweets];
		mySweets[0] = new RoundSweet();
		mySweets[1] = new SquareSweet();
		mySweets[2] = new TriangularSweet();

		SweetBox mySweetBox(mySweets, "I love you", "red");
		mySweetBox.Print();
		
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();

	}

}
