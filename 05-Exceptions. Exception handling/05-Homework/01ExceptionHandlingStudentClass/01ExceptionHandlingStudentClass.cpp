#include <iostream>

#include "Student.h"
#include "NameValueError.h"
#include "EGNValueError.h"
#include "FacultyNumberError.h"
#include <string>

using namespace std;

int main()
{
	bool isRunning = true;
	bool isReadyToPrint = true;
	while (isRunning)
	{
		isReadyToPrint = true;
		int numberOfStudents = 0;
		do
		{
			cout << "Please enter the number of students for the database between 1 and 10" << endl;
			cin >> numberOfStudents; cout << endl;
		} while (numberOfStudents < 1 || numberOfStudents > 10);

		Student bestStudent;
		int bestStudentIndex; // stores the index from the array if we wish to print directly from the array. if so we can  replace bestStudent.Print(); with studentDatabase[bestStudentIndex].Print()
		Student* studentDatabase;
		studentDatabase = new Student[numberOfStudents];

		try {
			for (int i = 0; i < numberOfStudents; ++i)
			{

				studentDatabase[i].Read();

				if (i == 0)
				{
					bestStudent.SetName(studentDatabase[i].GetName());
					bestStudent.SetEGN(studentDatabase[i].GetEGN());
					bestStudent.SetFacultyNumber(studentDatabase[i].GetFacultyNumber());
					bestStudent.SetGrade(studentDatabase[i].GetGrade());
					bestStudentIndex = 0;
				}
				else
				{
					if (studentDatabase[i].GetGrade() > bestStudent.GetGrade())
					{
						bestStudent.SetName(studentDatabase[i].GetName());
						bestStudent.SetEGN(studentDatabase[i].GetEGN());
						bestStudent.SetFacultyNumber(studentDatabase[i].GetFacultyNumber());
						bestStudent.SetGrade(studentDatabase[i].GetGrade());
						bestStudentIndex = i;
					}
				}

			}
			cin.ignore();
		}
		catch (NameValueError& ex)
		{
			cout << "A name value error has occurred:" << ex.what() << std::endl << "Retry?(y/n)";
			string input;
			getline(cin, input);
			isReadyToPrint = false;
			if (input == "n") isRunning = false;
			cin.ignore();
		}
		catch (EGNValueError& ex)
		{
			cout << "A name value error has occurred:" << ex.what() << std::endl << "Retry?(y/n)";
			string input;
			isReadyToPrint = false;
			getline(cin, input);
			if (input == "n") isRunning = false;
			cin.ignore();
		}
		catch (FacultyNumberError& ex)
		{
			cout << "A name value error has occurred:" << ex.what() << std::endl << "Retry?(y/n)";
			string input;
			isReadyToPrint = false;
			getline(cin, input);
			if (input == "n") isRunning = false;
			cin.ignore();
		}

		if (isRunning == true && isReadyToPrint == true)
		{
			cout << "Top student details are as follow:" << endl;
			bestStudent.Print();
			isRunning = false;
		}
	}
	return 0;
}