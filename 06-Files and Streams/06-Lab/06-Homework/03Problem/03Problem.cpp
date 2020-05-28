#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Encrypt(string, istream&, ostream&);
string Modify(string);

int main()
{
    ifstream inputFile;
    ofstream outputFile;

    string inputFileName = "";
    string outputFileName = "";
    string keyWord = "";

    cout << "Please enter the code word: " << endl;
    cin >> keyWord; cout << endl;

    if (keyWord.length() == 0)
    {
        cout << "Keyword cannot be empty.";
        return 1;
    }
    string modifiedKeyWord = Modify(keyWord);

    cout << "Please enter the input file name, including the extension: " << endl;
    cin >> inputFileName; cout << endl;

    inputFile.open(inputFileName);
    if (!inputFile)
    {
        cerr << "File " << inputFileName << " couldn't be opened" << endl;
        return 2;
    }

    cout << "Please enter the output file name, including the extension: " << endl;
    cin >> outputFileName; cout << endl;
	
    outputFile.open(outputFileName);
    if (!outputFile)
    {
        cout << "File wasn't found. New file with that name created." << endl;
        cerr << "File " << inputFileName << " couldn't be opened" << endl;
        return 2;
    }

    cout << modifiedKeyWord << endl;
	
	Encrypt(modifiedKeyWord, inputFile, outputFile);
    inputFile.close();
    outputFile.close();
    return 0;
}

string Modify(string key) // tried to modify code from Caesar cypher from Stackoverflow but I wasn't able to adapt it to the problem
{
    int count[26] = { 0 };
    char currentChar;
    bool isFound;
    string modifiedKeyWord = "";
	
    for (int i = 0; key[i] != '\0'; i++)
    {
        key[i] = toupper(key[i]);
        count[key[i] - 'A']++;
    }
	
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (count[key[i] - 'A'] != 0)
        {
            modifiedKeyWord = modifiedKeyWord + key[i];
            count[key[i] - 'A'] = 0;
        }
    }

    int newKeyLength = modifiedKeyWord.length();
    for (currentChar = 'Z'; currentChar >= 'A'; currentChar--)
    {
        isFound = false;
        for (int i = 0; i < newKeyLength; i++)
            if (currentChar == key[i])
            {
                isFound = true;
            }
        if (!isFound)
            modifiedKeyWord = modifiedKeyWord + currentChar;
    }
    return modifiedKeyWord;
}

void Encrypt(string keyWord, istream& inputFile, ostream& outputFile)
{
    string tempLineReader;
    getline(inputFile, tempLineReader);
    while (inputFile)
    {
        for (int i = 0; tempLineReader[i] != '\0'; i++)
        {
            if (isalpha(tempLineReader[i]))
            {
                outputFile << keyWord[toupper(tempLineReader[i]) - 'A'];
            }
            else
            {
                outputFile << tempLineReader[i];
            }
        }
        outputFile << endl;
        getline(inputFile, tempLineReader);
    }
}