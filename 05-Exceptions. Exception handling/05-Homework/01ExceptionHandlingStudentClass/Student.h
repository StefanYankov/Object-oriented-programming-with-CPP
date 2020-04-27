#pragma once
#include <ostream>

class Student
{
private:
	char* name;
	char* egn;
	char* facultyNumber;
	double grade;
public:
	Student();
	Student(char*, char*, char*, double);
	~Student();
	char* GetName() const;
	void SetName(char* name);

	char* GetFacultyNumber() const;
	void SetFacultyNumber(char*);
	
	char* GetEGN() const;
	void SetEGN(char*);
	
	double GetGrade() const;
	void SetGrade(double grade);

	bool IsBetterThan(Student s) const;
	void Print() const;
	void Read();

	friend std::ostream& operator << (std::ostream&, const Student&);
	friend std::istream& operator >> (std::istream&, Student&);
};


std::ostream& operator << (std::ostream&, const Student&);
std::istream& operator >> (std::istream&, Student&);
