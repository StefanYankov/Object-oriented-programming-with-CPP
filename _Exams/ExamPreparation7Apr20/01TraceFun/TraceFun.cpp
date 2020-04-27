#include "TraceFun.h"

TraceFun::TraceFun()
{

}

TraceFun::~TraceFun()
{
	this->SetOut("Function")
}

char* TraceFun::GetFunName() const
{
	return funName;
}

void TraceFun::SetFunName(const char* funName)
{
	this->funName = new char[strlen(funName) + 1];
	strcpy(this->funName, funName);
}

std::ostream& TraceFun::GetOut() const
{
	return out;
}

void TraceFun::SetOut(std::ostream& o)
{
	*out = &o;
}
