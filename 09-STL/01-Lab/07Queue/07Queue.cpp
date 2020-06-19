#include <iostream>
#include <queue>
#include <string>
#include <locale>

using namespace std;

int main()
{
	locale::global(locale("Bulgarian"));

	//декларираме опашка, която ще съхранява низове имена
	queue <string> names;
	//добавяме стойности към опашката
	names.push("Ivan");
	//опашките са подобни на векторите
	names.push("Nina");
	names.push("Magdalena");

	cout << "В момента в опашката има " << names.size() << " човека." << endl
		<< "Човекът в началото на опашката е " << names.front() << endl
		<< "Човекът в края на опашката е " << names.back() << endl << endl;

	cout << names.front() << " е напуснал!" << endl;
	names.pop();
	cout << "В момента в опашката има " << names.size() << " човека." << endl
		<< "Човекът в началото на опашката е " << names.front() << endl
		<< names.back() << " е все още най-отзад на опашката!" << endl;

	return 0;
}
