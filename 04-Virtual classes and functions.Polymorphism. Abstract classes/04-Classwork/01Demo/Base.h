#pragma once
class Base
{
public:
	Base();
	Base(int);
	~Base();
	int GetBase() const;
	void SetBase(int);

	virtual void Print() const;
private:
	int base;
};

