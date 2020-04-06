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

	void SetName(char*);
	void SetEGN(char*);

	const char* GetName() const;
	const char* GetEGN() const;

	friend std::ostream& operator << (std::ostream&, const People&);
};

