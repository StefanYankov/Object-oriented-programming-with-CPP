#include <iostream>
#include <vector>
#include <locale>
#include <stdexcept>

using namespace std;

void print_all(vector < int >& inputVector)
{
	cout << "v. size ()= " << inputVector.size() << endl;
	for (vector < int >::iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
}

int main()
{
	const int SIZE = 10;
	int values[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector <int> myVector(values, values + SIZE);
	print_all(myVector);
	myVector.insert(myVector.begin(), -1);
	myVector.insert(myVector.end(), 10);
	print_all(myVector);

	myVector.erase(myVector.begin());
	myVector.erase(myVector.end() - 1);
	print_all(myVector);

	myVector.erase(myVector.begin(), myVector.end());
	cout << "v. empty ()= " << boolalpha << myVector.empty() << "=" << noboolalpha << myVector.empty() << endl;

	try {
		myVector.at(1) = 10;
	}
	catch (out_of_range e) {
		cout << "out_of_range exception catched: " << e.what() << endl;
	}

	return 0;
}
