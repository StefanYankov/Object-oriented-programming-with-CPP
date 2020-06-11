#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string myData = "1024 3.1415926536 This is a test";

	istringstream stringInput(myData);

	int SSInteger = 0;
	double SSDouble = 0;

	stringInput >> SSInteger >> SSDouble;

	cout << "String stream input: " << endl;
	cout << "Integer = " << SSInteger << endl << "Double = " << SSDouble << endl;

	cout << stringInput.rdbuf() << endl;

	return 0;
}
