#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int inputInteger;
	double inputDouble;
	string inputString;

	cout << "Please enter an integer, double and string values: " << endl;

	cin >> inputInteger >> inputDouble;
	cin.ignore();
	
	getline(cin, inputString);
	ostringstream outputString;

	outputString << "From the console, the user inputted the following values: " << endl;
	outputString << "Integer = " << inputInteger << endl;
	outputString << "Double = " << inputDouble << endl;
	outputString << "String = " << inputString << endl;
	outputString << "This is the end." << endl;

	cout << outputString.str() << endl;
	
}