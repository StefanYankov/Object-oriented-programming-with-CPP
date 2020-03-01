#pragma once
#include "Head.h"
#include "Handle.h"

class Hoe
{
public:
	Hoe();
	Hoe(Head, Handle);

	void PrintHoe();

private:
	Head myHead;
	Handle myHandle;
};

