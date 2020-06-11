#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("input.tga", ios::in | ios::binary);
	if (!input)
	{
		cerr << "Couldn't open input.tga" << endl;
		return 1;
	}

	ofstream backup("backup.tga", ios::out | ios::binary);
	if (!backup)
	{
		cerr << "Couldn't open backup.tga" << endl;
		return 2;
	}

	backup << input.rdbuf();

	backup.close();

	ofstream output("output.tga", ios::out | ios::binary);
	if (!output)
	{
		cerr << "Couldn't open output.tga" << endl;
		return 4;
	}

	char header[18]; // tga header will be stored here
	input.seekg(0, ios::beg); // move the pointer to the start of the file
	input.read(header, 18); // read only 18 bytes from the file

	output.seekp(0, ios::beg);
	output.write(header, sizeof(header));

	input.seekg(12, ios::beg); // get tga size -> height and length stored on the 12th bit

	uint16_t width = 0;
	uint16_t height = 0;

	input.read((char*)&width, sizeof(width)); // typecasting the ones and zeros to a number
	input.read((char*)&height, sizeof(height));

	// pixel array to add the filter -> 3 bites one for Red, one for Green and one for Blue
	char pixel[3]; // even though is RGB the sequence is Blue, Green, Red

	// moving the get and put points to the beginning of the image, just after the header
	input.seekg(18, ios::beg);
	output.seekp(18, ios::beg);

	int mode;
	cout << "Please select a colouring mode: " << endl;
	cout << "1 -> blue" << endl;
	cout << "2 -> red" << endl;
	cout << "3 -> green" << endl;
	cout << "4 -> black and white" << endl;
	cout << "5 -> black screen" << endl;
	cout << "6 -> BG flag" << endl;

	cin >> mode;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			input.read(pixel, 3);
			switch (mode)
			{
			case 1:
				// blue
				pixel[0] = pixel[0]; // so we don't change it
				pixel[1] = 1;
				pixel[2] = 0;
				break;
			case 2:
				// red
				pixel[0] = 1;
				pixel[1] = 0;
				pixel[2] = pixel[2];
				break;
			case 3:
				// green
				pixel[0] = 1;
				pixel[1] = pixel[1];
				pixel[2] = 35;
				break;
			case 4:
				// black and white
				pixel[0] = pixel[1];
				pixel[2] = pixel[1];
				break;
			case 5:
				// black screen
				pixel[0] = 0;
				pixel[1] = 0;
				pixel[2] = 0;
				break;
			case 6:
				// Bulgarian flag
				if (row <= height / 3)
				{
					// white
					pixel[2] = 255;
				}
				else if (row <= (2 * height) / 3)
				{
					// green;
					pixel[1] = 255;
				}
				else
				{
					pixel[0] = 255;
					pixel[1] = 255;
					pixel[2] = 255;
				}
				break;
			}
			output.write(pixel, 3);
		}
	}

	output.close();
	input.close();

	return 0;
}

