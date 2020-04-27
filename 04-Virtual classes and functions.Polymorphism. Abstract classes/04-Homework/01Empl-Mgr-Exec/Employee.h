#pragma once
class Employee
{
public:
	Employee();
	Employee(const char*, double, int, int);
	~Employee();
	Employee(const Employee&);
	Employee& operator=(const Employee&);
	char* GetName() const;
	void SetName(const char* name);

	double GetSalary() const;
	void SetSalary(double);

	int GetTenure(int);
	void SetTenure(int, int);

	virtual void Print() const;
	void PrintAll();

private:
	char* name;
	double salary;
	int tenure[2];
};

