#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// sample file name Hello.txt
// sample text inside the file
/*
Hello, I am Stefan!
I am 20 years old.
I come from Troyan.
 */
// No new line after "Troyan."

// Sample empty file Goodbye.txt

// Sample file that doesn't exist 

int main()
{
    bool isEmpty = false;
	do
	{
        string fileName = "";
        string fileType = ".txt";

        int charCount = 0;
        int wordCount = 1; // the algorithm doesn't count the first word. All separated entities - including numbers - are counted as words
        int lineCount = 1; // the the algorithm doesn't count the first line.

        char currentChar;
        cout << "Please enter the name of the file and the program will automatically add extension .txt" << endl;
        cin >> fileName;


        string fullFileName = fileName + fileType;
        ifstream inputFile(fullFileName);
        if (!inputFile)
        {
            cerr << "File " << fileName << " with an extension " << fileType << " couldn't be opened" << endl;
            return 2;
        }
        if (inputFile.peek() == ifstream::traits_type::eof()) // got it from Stackoverflow. Couldn't come up with a better solution
        {
            isEmpty = true;
            cout << "File " << fullFileName << " is empty." << endl;
            break;
        }
        
        inputFile.get(currentChar);
        while (!inputFile.eof())
        {

            if (currentChar == '\n')
            {
                lineCount++;
                wordCount++; // to also include first word from a line as we don't have a ' ' infront of it, hence the next check will not count it
            }
            else if (currentChar == ' ')
            {
                wordCount++;
                charCount++; // to include also white spaces like as they are counted for example in twitter
            }
            else
            {
                charCount++;
            }
            inputFile.get(currentChar);
        }

        cout << "The number of characters in the file (including white spaces) is " << charCount << endl
            << "The number of words in the file is " << wordCount << endl
            << "The number of lines in the files is " << lineCount << endl;

        inputFile.close();
	}
	while (!isEmpty);
    return 0;
}
