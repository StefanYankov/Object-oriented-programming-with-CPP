#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector < int > arr;

	cout << "Initial vector size : " << arr.size() << endl
	     << "Initial vector capacity : " << arr.capacity() << endl;
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	cout << "Vector size : " << arr.size() << endl
		 << "Vector capacity: " << arr.capacity() << endl;
	int sum = 0;
	for (vector < int >::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << endl;
		sum += *it;
	}

	cout << "sum = " << sum << endl;

	return 0;
}
