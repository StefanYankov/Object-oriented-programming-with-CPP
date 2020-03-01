#include "Head.h"

Head::Head()
{
	heigth = 5;
}
Head::Head(int heigth)
{
	this->heigth = heigth;
}

int Head::GetHeigth() const
{
	return heigth;
}
void Head::SetHeigth(int heigth)
{
	this->heigth = heigth;
}
