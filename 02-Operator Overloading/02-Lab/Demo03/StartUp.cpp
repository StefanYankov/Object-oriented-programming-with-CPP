#include <iostream>
#include "Human.h"
using namespace std;

int main()
{

	char firstName[] = "Serafim";
	char familyName[] = "Gerasimoff";
	Human male1(firstName, familyName, true, false);

	char firstNameFemale1[] = "Dala";
	char familyNameFemale1[] = "Vera";
	Human female1(firstNameFemale1, familyNameFemale1, true, false);

	char firstNameFemale2[] = "Avtonomka";
	char familyNameFemale2[] = "Torimatsova";
	Human female2(firstNameFemale2, familyNameFemale2, true, true);

	female1 = female1 + male1;

	cout << female1.GetName() << " " << female1.GetFamilyName() << endl;

	female2 = female2 + male1;

	cout << female2.GetName() << " " << female2.GetFamilyName() << endl;

}
