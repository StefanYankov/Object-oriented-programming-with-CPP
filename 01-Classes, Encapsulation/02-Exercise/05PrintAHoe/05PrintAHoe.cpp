#include <iostream>
#include "Hoe.h"
#include "Handle.h"
#include "Head.h"

int main()
{
	Handle myHandle(1, 10);
	Head myHead(5);
	Hoe myHoe(myHead, myHandle);

	myHoe.PrintHoe();

	return 0;
}
