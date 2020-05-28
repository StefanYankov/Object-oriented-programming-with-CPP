#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// print array
void PrintArray(int*, unsigned);

// function for array elements sum
int SumArray(int*, unsigned);
// average of the array
double AverageArray(int*, unsigned);

// min
int MinValue(int*, unsigned);
// max
int MaxValue(int*, unsigned);

int main()
{
	// var for array elements count
	unsigned size = 0;

	// read from file
	ifstream inputStream("Input.txt");
	if (!inputStream)
	{
		cerr << "File Input.txt couldn't be opened!";
		return 1;
	}

	inputStream >> size;
	cout << "Number of elements in the array: " << size << endl;
	
	// array  - what type of array?
	int* fileArray = new int[size];

	// read array from file input.txt
	for (int i = 0; i < size; i++)
	{
		inputStream >> fileArray[i];
	}

	PrintArray(fileArray, size);
	
	// char array variable first name and last name
	char firstName[15];
	char lastName[15];

	// read names from file
	inputStream >> firstName;
	inputStream >> lastName;
	inputStream.ignore();
	cout << "My name is " << firstName << ' ' << lastName << '.'<< endl;
	
	// one variable for which university and what year
	string universityInfo;
	getline(inputStream, universityInfo);
	cout << "My university information is as follows: " << universityInfo << endl;
	
	// char and read it from file
	char inputChar;
	inputStream >> inputChar;
	cout << "The character is : " << inputChar << endl;
	inputStream.close();

	ofstream outputStream("Output.txt");
	if (!outputStream)
	{
		cerr << "File \"Output.txt\" couldn't be created/opened!" << endl;
		return 2;
	}

	outputStream << "Array elements number: " << size << endl;
	outputStream << "Array elements: ";
	outputStream << fileArray[0];
	for (int i = 1; i < size; i++)
	{
		outputStream << ' ' << fileArray[i];
	}
	outputStream << endl;
	outputStream << "The minimum integer in the array is: " << MinValue(fileArray, size) << endl;
	outputStream << "The maximum integer in the array is: " << MaxValue(fileArray, size) << endl;
	outputStream << "The sum of the integers in the array is: " << SumArray(fileArray, size) << endl;
	outputStream << "The average of the integers in the array is:" << AverageArray(fileArray, size) << endl;
	outputStream.close();

	inputStream.open("Output.txt");
	if (!inputStream)
	{
		cerr << "File \"Output.txt\" couldn't be opened!" << endl;
		return 3;
	}
	const unsigned length = 100;
	char line[length +1];
	cout << "====================" << endl;
	cout << "Read file \"Output.txt\" 's content:" << endl;
	while (inputStream.getline(line,length))
	{
		cout << line << endl;
	}

	try
	{
		if (!inputStream.eof())
		{
			throw exception("Bad data.");
		}
	}
	catch (exception & ex)
	{
		cerr << "Exception caught: "<< ex.what() << endl;
	}


	
	// inputStream cannot be used as the previous while loop has reached end_of_file
	inputStream.close();

	cout << "====================" << endl;
	cout << "Read file \"01FilesDemo.cpp\" 's content:" << endl;
	inputStream.open("01FilesDemo.cpp");
	if (!inputStream)
	{
		cerr << "File \"01FilesDemo.cpp\" couldn't be opened!" << endl;
		return 4;
	}
	while (inputStream.getline(line, length))
	{
		cout << line << endl;
	}
	inputStream.close();
	
	// free up dynamic memory
	if (fileArray != nullptr)
	{
		delete[] fileArray;
		fileArray = nullptr;
	}
	return 0;
}

void PrintArray(int* array, unsigned size)
{
	cout << array[0];
	for (int i = 0; i < size; i++)
	{
		cout << ' ' << array[i];
	}
	cout << endl;
}

int SumArray(int* array, unsigned size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	
	return sum;
}

double AverageArray(int* array, unsigned size)
{
	double average = SumArray(array, size) * 1. / size;
	return average;
}

int MinValue(int* array, unsigned size)
{
	int min = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

int MaxValue(int* array, unsigned size)
{
	int max = array[0];

	for (int i = 0; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	
	return max;
}