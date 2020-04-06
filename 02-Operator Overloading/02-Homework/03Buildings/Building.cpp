#include "Building.h"
#include <iostream>

Building::Building()
{
	address = "default address";
	plannedFloors = 1;
	buildFloors = 1;
	plannedEntrances = 1;
	buildEntrances = 1;
}

Building::Building(string address, int plannedFloors, int buildFloors, int plannedEntrances, int buildEntrances)
{
	this->SetAddress(address);
	this->SetPlannedFloors(plannedFloors);
	this->SetBuildFloors(buildFloors);
	this->SetPlannedEntrances(plannedEntrances);
	this->SetBuildEntrances(buildEntrances);
}
/*
Building::~Building()
{
	std::cout << "Building constructed." << std::endl;
}
*/
Building::Building(const Building& rhs)
{
	this->SetAddress(rhs.GetAddress());
	this->SetPlannedFloors(rhs.GetPlannedFloors());
	this->SetBuildFloors(rhs.GetBuildFloors());
	this->SetPlannedEntrances(rhs.GetPlannedEntrances());
	this->SetBuildEntrances(rhs.GetBuildEntrances());
}

string Building::GetAddress() const
{
	return this->address;
}

void Building::SetAddress(string address)
{
	this->address = address;
}

int Building::GetPlannedFloors() const
{
	return this->plannedFloors;
}

void Building::SetPlannedFloors(int plannedFloors)
{
	if (plannedFloors > 0)
	{
		this->plannedFloors = plannedFloors;
	}
	else
	{
		std::cout << "you need at least one planned floor";
	}
}

int Building::GetBuildFloors() const
{
	return this->buildFloors;
}

void Building::SetBuildFloors(int buildFloors)
{
	if (buildFloors >= 0)
	{
		this->buildFloors = buildFloors;
	}
	else
	{
		std::cout << "You cannot have negative build floors";
	}
}

int Building::GetPlannedEntrances() const
{
	return this->plannedEntrances;
}

void Building::SetPlannedEntrances(int plannedEntrances)
{
	if (plannedEntrances > 0)
	{
		this->plannedEntrances = plannedEntrances;
	}
	else
	{
		std::cout << "you need at least one planned etrance";
	}
}

int Building::GetBuildEntrances() const
{
	return this->buildEntrances;
}

void Building::SetBuildEntrances(int buildEntrances)
{
	if (buildEntrances >= 0)
	{
		this->buildEntrances = buildEntrances;
	}
	else
	{
		std::cout << "You cannot have negative build entrances";
	}
}

void Building::Print() const
{
	std::cout << "Building details: " << std::endl;
	std::cout << "address: " << this->GetAddress() << std::endl;
	std::cout << "planned floors: " << this->GetPlannedFloors() << std::endl;
	std::cout << "build floors: " << this->GetBuildFloors() << std::endl;
	std::cout << "planned entrances: " << this->GetPlannedEntrances() << std::endl;
	std::cout << "build entrances:" << this->GetBuildEntrances() << std::endl;
}

Building& Building::operator=(const Building& rhs)
{
	if (this != &rhs)
	{
		this->address = rhs.GetAddress();
		this->plannedFloors = rhs.GetPlannedFloors();
		this->buildFloors = rhs.GetBuildFloors();
		this->plannedEntrances = rhs.GetPlannedEntrances();
		this->buildEntrances = rhs.GetBuildEntrances();
	}
	return *this;
}

Building& Building::operator+(int buildFloors) // not creating a new object as we are only adding an additional floor to the existing building
{
	this->SetBuildFloors(this->GetBuildFloors() + buildFloors);
	return *this;
}

Building& Building::operator+=(int buildFloors)
{
	this->SetBuildFloors(this->GetBuildFloors() + buildFloors);
	return *this;
}


Building operator+(const int lhs, Building& rhs) // build entrances ++
{
	Building temporary;
	temporary.SetAddress(rhs.GetAddress());
	temporary.SetPlannedFloors(rhs.GetPlannedFloors());
	temporary.SetBuildFloors(rhs.GetBuildFloors());
	temporary.SetPlannedEntrances(rhs.GetPlannedEntrances());
	temporary.SetBuildEntrances(lhs + rhs.GetBuildEntrances());


	return temporary;
}

Building& operator+=(const int lhs, Building& rhs)
{
	Building temporary = lhs + rhs;
	rhs = temporary;
	return rhs;
}
