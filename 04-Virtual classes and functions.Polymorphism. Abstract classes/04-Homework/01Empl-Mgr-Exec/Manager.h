#pragma once
#include "Employee.h"
#include <string>
class Manager
    : public Employee
{
public:
    Manager();
    Manager(const char*, double, int, int, std::string);
    Manager(const Manager&);
    Manager& operator=(const Manager&);
public:
    std::string GetDepartament() const;
    void SetDepartament(std::string);

    virtual void Print() const;
private:
    std::string departament;
};

