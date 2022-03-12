#pragma once
#include <iostream>

using namespace std;

class Example
{
private:
	int a;
	int b;
	int* dynamicValue;
	unsigned length;
	static unsigned count;
public:
	Example(); // default ctor
	explicit Example(int); //	constructor cannot be used  for implicit conversions and copy-initialization. 
	// Big Five
	Example(int, int, unsigned, int*);
	~Example();
	Example(const Example&);
	Example& operator=(const Example&); // a=b=c / a=a

	// set and get functions
	int GetA() const;
	void SetA(int);

	int GetB() const;
	void SetB(int);

	int GetDynamicValue(int) const;
	void SetDynamicValue(int*);

	unsigned GetLength() const;
	void SetLength(unsigned);

	static unsigned GetCount();

	void Print() const;

	//friend functions (if needed)
	friend Example operator+(const Example&, const Example&);
	friend ostream& operator<<(std::ostream&, const Example&);
	// end of friend functions
	Example operator-(const Example&) const;
	Example& operator-=(const Example&);
	operator int() const; // this function will make the class compatible with int

};

//a+b
//Example operator+(const Example&, const Example&); // not needed to have it twice

