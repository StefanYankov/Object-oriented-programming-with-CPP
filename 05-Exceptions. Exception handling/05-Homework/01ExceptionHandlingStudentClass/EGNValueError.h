#pragma once
#include <stdexcept>

class EGNValueError
	: public std::logic_error
{
public:
	EGNValueError(std::string);
};