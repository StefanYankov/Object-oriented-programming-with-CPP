#include <iostream>
#include <list>
#include <locale>

using namespace std;

void print_all(list <int>& inputList)
{
	for (list <int>::iterator it = inputList.begin(); it != inputList.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
}

int main()
{
	const int SIZE = 10;
	int values[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> myList(values, values + SIZE);
	print_all(myList);

	myList.insert(myList.begin(), -1);
	myList.insert(myList.end(), 10);
	print_all(myList);

	myList.erase(myList.begin());
	list<int>::iterator last = myList.end();
	myList.erase(--last);
	print_all(myList);
	myList.erase(myList.begin(), myList.end());
	cout << "l. empty()= " << boolalpha << myList.empty() << "= " << noboolalpha << myList.empty() << endl;
	myList.push_back(10);
	myList.push_back(1);
	myList.push_back(0);
	print_all(myList);

	myList.pop_front();
	print_all(myList);
	
	return 0;
}
