#pragma once


class RandomStream
{
private:
	int stringLength;
	bool hasWhiteSpace;
	int randomInteger();
	double randomDouble();
	void randomString(char*);
public:
	RandomStream(int = 80, bool = true);

	int getStringLength() const;
	void setStringLength(int);

	bool getHasWhiteSpace() const;
	void setHasWhiteSpace(bool);
	
	RandomStream& operator>>(int&);
	RandomStream& operator>>(double&);
	RandomStream& operator>>(unsigned&);
	RandomStream& operator>>(char *);
};

