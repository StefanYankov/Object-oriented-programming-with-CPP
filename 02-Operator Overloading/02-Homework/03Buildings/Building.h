#pragma once
#include <string>
using namespace std;

class Building
{
private:
	string address;
	int plannedFloors;
	int buildFloors;
	int plannedEntrances;
	int buildEntrances;
public:
	Building();
	Building(string, int, int, int, int);
	//~Building(); //no dynamic memory hence we don't need a defined dector
	Building(const Building&);
	Building& operator=(const Building&);
	Building& operator+(int);
	Building& operator+=(int);

	string GetAddress() const;
	void SetAddress(string);

	int GetPlannedFloors() const;
	void SetPlannedFloors(int);

	int GetBuildFloors() const;
	void SetBuildFloors(int);

	int GetPlannedEntrances() const;
	void SetPlannedEntrances(int);

	int GetBuildEntrances() const;
	void SetBuildEntrances(int);

	void Print() const;
};

Building operator+(const int, Building&);
Building& operator+=(const int, Building&);
