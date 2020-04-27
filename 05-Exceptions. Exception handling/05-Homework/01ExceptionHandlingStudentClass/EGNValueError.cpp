#include "EGNValueError.h"

EGNValueError::EGNValueError(std::string reason)
	:logic_error(reason)
{
}