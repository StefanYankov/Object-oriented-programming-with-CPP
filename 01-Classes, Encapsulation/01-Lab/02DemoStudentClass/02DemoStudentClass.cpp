#include "Student.h"
#include <iostream>


using namespace std;

int main()
{
	Student s;
	s.read();

	Student ivan("Ivan Ivanov", 5.67);
	cout << "Is " << ivan.getName() << " a better student than " << s.getName() << "? " << boolalpha << ivan.is_better_than(s) << endl;
	return 0;
}
