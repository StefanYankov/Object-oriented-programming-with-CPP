#pragma once
#include "Manager.h"
class Executive
	: public Manager
{
private:
public:
	Executive();
	Executive(const char*, double, int, int, std::string);
	Executive(const Executive&);
	Executive& operator=(const Executive&);
	virtual void Print() const;
};

