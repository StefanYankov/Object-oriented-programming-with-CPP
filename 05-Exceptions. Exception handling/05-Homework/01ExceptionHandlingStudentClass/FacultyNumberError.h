#pragma once
#include <stdexcept>

class FacultyNumberError
	: public std::logic_error
{
public:
	FacultyNumberError(std::string);
};

