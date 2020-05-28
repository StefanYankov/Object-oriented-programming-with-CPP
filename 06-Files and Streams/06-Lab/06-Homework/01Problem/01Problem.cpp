#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outputData;
    outputData.open("Hello.txt");
    string fileInput = "Hello, World!\n";
    outputData << fileInput;
    outputData.close();

    ifstream inputData;
    inputData.open("Hello.txt");

    string textFromFile;
    getline(inputData, textFromFile);
	//    cout << textFromFile;
    inputData.close();

    return 0;
}
