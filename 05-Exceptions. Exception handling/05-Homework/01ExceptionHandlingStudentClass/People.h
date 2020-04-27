#pragma once
#include <iostream>

class People
{
private:
	char* name;
	char* egn;
public:
	People();
	People(char*, char*);
	People(const People&);

	~People();

	void set_name(char*);
	void set_egn(char*);

	virtual char* get_name() const;
	virtual char* get_egn() const;

	virtual void print() const;

	friend std::ostream& operator << (std::ostream&, const People&);
	friend std::istream& operator >> (std::istream&, People&);
};
