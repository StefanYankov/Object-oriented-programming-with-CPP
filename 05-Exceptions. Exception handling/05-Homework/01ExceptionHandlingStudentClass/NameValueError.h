#pragma once
#include <stdexcept>

class NameValueError
	: public std::logic_error
{
public:
	NameValueError(std::string);
};