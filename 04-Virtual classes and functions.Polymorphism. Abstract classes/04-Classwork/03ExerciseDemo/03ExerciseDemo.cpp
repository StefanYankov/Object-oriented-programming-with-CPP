#include<iostream>
#include <string>
#include <typeinfo>
#include "Employee.h"
#include "Manager.h"
#include "Engineer.h"
#include "Researcher.h"

using namespace std;

int main()
{
	Employee** employees;
	unsigned num_of_employees, num_of_managers, num_of_engineers, num_of_researchers;
	bool flag = true;
	unsigned counter;
	while (flag) {
		cout << "How many employees you have? \n";
		cin >> num_of_employees;
		if (num_of_employees) {
			cout << "How many managers you have?\n";
			cin >> num_of_managers;
			if (num_of_managers < num_of_employees) {
				cout << "How many engineers you have?\n";
				cin >> num_of_engineers;
				if ((num_of_engineers + num_of_managers) < num_of_employees) {
					cout << "How many researches you have?\n";
					cin >> num_of_researchers;
					if ((num_of_engineers + num_of_managers + num_of_researchers) < num_of_employees) {
						flag = false;
						continue;
					}
				}
			}
			cout << "Number of managers, engineers and researches should be less then total number of employees." << endl;
			continue;
		}
		cout << "Number of employeers cannot be zero." << endl;
	}
	employees = new Employee * [num_of_employees];
	for (counter = 0; counter < num_of_managers; counter++) {
		employees[counter] = new Manager("Manager", "Managin", 1000.0f, counter + 2, 25);
	}
	for (; counter < (num_of_managers + num_of_engineers); counter++) {
		employees[counter] = new Engineer("Engi", "Engineer", float(counter) * 900.0f, float(counter) / 3.0f, counter, "Electrical");
	}
	for (; counter < (num_of_managers + num_of_engineers + num_of_researchers); counter++) {
		employees[counter] = new Researcher("Rese", "Researcher", 850.0f, "University of Maryland", "Cosmic candy production");
	}
	for (; counter < num_of_employees; counter++) {
		employees[counter] = new Employee("Empy", "Employee", float(counter) * 10.0f);
	}
	for (int n = 0; n < num_of_employees; n++) {
		employees[n]->Print();
	}
	system("PAUSE");
}
