#include <iostream>
#include <fstream>

#include "RandomStream.h"
#include "Data.h"
#include "FileManipulator.h"

int main()
{
	unsigned size = sizeof(Data);
	std::cout << "The size of Data is: " << size << std::endl;
	const int N = 10;
	Data myArray[N];
	int myInteger;
	double myDouble;
	RandomStream randomInput;
	randomInput >> myInteger >> myDouble;
	std::cout << myInteger << std::endl;
	std::cout << myDouble << std::endl;

	for (int i = 0; i < N; i++)
	{
		randomInput >> myInteger >> myDouble;
		myArray[i] = Data(myDouble, myInteger);
	}
	
	std::ofstream binaryFile("Data.bin", std::ios::out | std::ios::binary);
	binaryFile.write((char*)&N, sizeof(N));
	
	for (int i = 0; i < N; i++)
	{
		std::cout << myArray[i] << std::endl;
		binaryFile.write((char*)&myArray[i], size);
	}
	binaryFile.close();

	std::cout << std::endl << "================================" << std::endl;

	Data myArray2[N];
	int numberOfObjects = 0;
	std::ifstream readBinaryFile("Data.bin", std::ios::in | std::ios::binary);
	readBinaryFile.read((char*)&numberOfObjects,sizeof(numberOfObjects));
	for (int i = 0; i < numberOfObjects; i++)
	{
		readBinaryFile.read((char*)&myArray2[i], size);
		std::cout << FileManipulator(20,8) << myArray2[i] << std::endl;
	}
	// save to .txt
	std::ofstream fileOutput("Data.txt");

	if (!fileOutput)
	{
		std::cerr << "Couldn't open/create \"Data.txt\"";
		return 2;
	}

	fileOutput << "count = " << numberOfObjects << std::endl;
	for (int i = 0; i < numberOfObjects; ++i)
	{
		fileOutput << myArray2[i] << std::endl;
	}
	fileOutput.close();
	return 0;
}
