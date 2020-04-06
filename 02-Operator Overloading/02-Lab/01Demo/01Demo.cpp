#include <iostream>
#include "Example.h"

using namespace std;

int main()
{
	Example myExample;
	Example myExample2;

	cout << "Object a:" << endl;
	myExample.Print();

	cout << endl;
	cout << "Object b:" << endl;
	myExample2.Print();

	Example result = myExample + myExample2; // copy ctor

	cout << endl;
	cout << "Object a+b:" << endl;
	result.Print();


	Example result1; // default ctor
	result1 = myExample + myExample2; // operator=

	cout << endl;
	cout << "Object a+b:" << endl;
	(myExample + myExample2).Print();

	std::cout << std::endl;

	cout << endl;
	cout << "Object a-b:" << endl;
	(myExample - myExample2).Print();

	cout << "object 1: " << myExample;
	cout << endl;
	cout << "object 2: " << myExample2;
	
	cout << myExample + 2; // myExample + Example(a)
	cout << 33 + myExample;

	Example::GetCount();

	return 0;
}
