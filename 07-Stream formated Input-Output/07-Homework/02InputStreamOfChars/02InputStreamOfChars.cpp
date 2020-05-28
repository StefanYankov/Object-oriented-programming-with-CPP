#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	/*
	char c1 = 'S';
	char c2 = 't';
	char c3 = 'e';
	char c4 = 'f';

	char str1[11];
	cin.get(str1, 5, '\n').ignore().get(c1).get(c2).get(c3).get(c4);
	*/
	// b)

	char buffer;
	// sample input file text
	/*
	 *Serafim Gerasimoff
	 *99 years old
     *Retired
	 * 
	 */
	ifstream fin("Input.txt"); 
	if (!fin) 
	{
		cerr << "File Input.txt couldn't be opened!";
		return 1;
	}
	ofstream fout("Output.txt");
	if (!fout)
	{
		cerr << "File Output.txt couldn't be opened!";
		return 2;
	}

	while (fin && fin.get(buffer))
	{

		//	if (!isspace(buffer)) // uncomment this logical check for problem "V"
		//  {
		fout.put(buffer);
		//	}
		if (!fin.eof())
		{
			cout << "End of file reached." << endl;
		}
	}
	
	fin.close();
	fout.close();
	return 0;
}
