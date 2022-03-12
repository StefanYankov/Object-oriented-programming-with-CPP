/*
 * car-- or --car decreased the price by 100 leva.
 *
 * compare the cars by redefining ">". Comparison is done by  price and if they are equal - by year.
 * redefine also >= and !
 */

#include <iostream>
#include "Car.h"
#include "CarDealer.h"
using namespace std;
int main()
{
	/*
	Car car1(new char[] {" "},5,650,2020,100000.0);
	Car car2 = car1;
	Car car3;
	cout << "Default values for car3" << endl;
	car3.Print();
	cout << endl;

	car3 = car2;
	car3.Print();

	car1.Print();
	cout << endl;
	car2.Print();
	cout << endl;
	car3.Print();

	car2.SetMade(new char[] {"Mercedes"});
	cout << endl;
	car1.Print();
	cout << endl;
	car2.Print();
	cout << endl;
	car3.Print();
	//cout << endl;
	//cout << car3 << endl;
	cout << car1.GetHorsePower() << endl;
	cout << car1 * 5 << endl;
	*/

	Car car1;
	char made[] = "BMW";
	Car car2(made, 5, 2000, 2018, 1000);
	Car car3(car2);
	Car car4 = car2;

	std::cout << car2 << std::endl;
	std::cout << "If we upgrade it: " << std::endl << car2 + 300 << endl;
	cout << "Current state of my car: " << endl << car2 << endl;
	car2 += 300;
	cout << "After upgrade: " << endl;
	cout << car2 << endl;

	car1 = car2--;
	car3 = --car2;

	cout << "Car1: " << car1 << endl;
	cout << "Car2: " << car2 << endl;
	cout << "Car3: " << car3 << endl;

	cout << "Car2 triple post decrement: " << ((car2--)--)-- << endl;

	cout << "Is Car2 > Car3? " << boolalpha << (car2>car3) << endl;
	cout << "Is Car3 == Car1? " << boolalpha << (car3==car1) << endl;
	cout << "Is Car2 < Car3? " << boolalpha << (car2 < car3) << endl;
	cout << "Is Car3 <= Car1? " << boolalpha << (car3 <= car1) << endl;

	cout << endl << "Car Dealer Details" << endl;
	Car cars[4] = {car1, car2, car3, car4};
	CarDealer carDealer1("Serafim Gerasimoff", 4, cars);
	cout << carDealer1 << endl;

	cout << carDealer1.GetName() << "'s first car: " << carDealer1[0] << endl;

	cout << "Price for all cars: " << carDealer1() << endl;
	cout << "Price for cars 1 to 3: " << carDealer1(1,3) << endl;

	return 0;
}
