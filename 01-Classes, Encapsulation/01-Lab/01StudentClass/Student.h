#pragma once
class Student
{

private:
	const char* name;
	unsigned facultyNumber;
	const char* major;
public:
	const char* GetName() { return name; }
	void SetName(const char* name) { this->name = name; }

	unsigned GetFacultyNumber() { return facultyNumber; }
	void SetFacultyNumber(unsigned facultyNumber) { this->facultyNumber = facultyNumber; }

	const char* GetMajor() { return major; }
	void SetMajor(const char* major) { this->major = major; }

	Student();
	Student(const char*, unsigned, const char*);

	~Student();

	void ToString();
};

