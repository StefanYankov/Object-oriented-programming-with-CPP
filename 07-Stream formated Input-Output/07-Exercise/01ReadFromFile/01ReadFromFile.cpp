#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fileInput("Tsts.txt");

	if(!fileInput)
	{
		cerr << "File Tsts.txt cannot be opened!" << endl;
		return 1;
	}
	
	string buffer;
	
	while (getline(fileInput, buffer))
	{
		cout << buffer << endl;
	}

	fileInput.close();


	return 0;
}
