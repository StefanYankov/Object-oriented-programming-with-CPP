#pragma once
#include "Head.h"
class Snake : public Head
{
public:
	Snake();
	Snake(char, int, int, int);
	int GetLength() const;
	void SetLength(int);

	int GetWidth() const;
	void SetWigth(int);

	void Print();
private:
	int length;
	int wigth;
};

