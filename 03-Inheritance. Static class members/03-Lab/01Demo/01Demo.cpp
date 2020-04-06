#include <iostream>
#include "People.h"
#include "Student.h"

using namespace std;

int main()
{
	char fullName[] = "Emiliyan Petkov";
	char EID[] = "0888468897";
	People myPerson(fullName, EID);
	Student myStudent;
	cout << myPerson;
	return 0;
}