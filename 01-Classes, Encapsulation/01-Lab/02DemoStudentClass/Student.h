#pragma once
class Student
{
public:
	Student();
	Student(const char*, double);

	char* getName() const;
	void setName(char* name);

	double getGrade() const;
	void setGrade(double grade);

	bool is_better_than(Student s) const;
	void print() const;
	void read();
private:
	char* name;
	double grade;
};

