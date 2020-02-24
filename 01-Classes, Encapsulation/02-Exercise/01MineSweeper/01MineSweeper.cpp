#include <iostream>
#include "CMine.h"
#include "CPlayer.h"

using namespace std;

int main()
{

	CMine mine;
	CMine mine1(20, '@');
	CMine mine2(22, '&');
	cout << " Mine default: " << endl;
	cout << mine.getCount() << endl;
	cout << mine.getIcon() << endl;
	unsigned x;
	cin>> x;
	mine.setCount(x);

	cout << " Mine1: " << endl;
	cout << mine1.getCount() << endl;
	cout << mine1.getIcon() << endl;

	cout << " Mine2: " << endl;
	cout << mine2.getCount() << endl;
	cout << mine2.getIcon() << endl;

	CMine* pmine = & mine;
	cout << pmine -> getCount() << endl;
	cout << pmine -> getIcon() << endl;

	pmine = new CMine();
	if (pmine != nullptr) {
		delete pmine;
		pmine = nullptr;
	}
	pmine = new CMine(99, '%');
	cout << pmine -> getCount() << endl;
	cout << pmine -> getIcon() << endl;

}
