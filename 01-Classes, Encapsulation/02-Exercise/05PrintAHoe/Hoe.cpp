#include "Hoe.h"
#include "Head.h"
#include "Handle.h"
#include <iostream>

Hoe::Hoe()
{

}
Hoe::Hoe(Head myHead, Handle myHandle)
{
	this->myHead = myHead;
	this->myHandle = myHandle;
}

void Hoe::PrintHoe()
{
	int headRows = myHead.GetHeigth();
    for (int i = 1; i <= headRows; i++)
    {
        for (int j = headRows - 1; j>= i; j--)
        {
            std::cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    int handleDiameter = myHandle.GetDiameter();
    int handleRows = myHandle.GetLength();
    int handleSpacing = (headRows - 1) / 2;
    for (int i = 0; i < handleRows; i++)
    {
        for (int j = 0; j < handleSpacing; j++)
        {
            std::cout << "  ";
        }
        for (int k = 0; k < handleDiameter; k++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}


