#pragma once
class CMine
{
public:
	CMine();
	CMine(unsigned, char);

	~CMine();

	int setCount(unsigned);
	int setIcon(char);

	unsigned getCount() const;
	char getIcon() const;

private:
	unsigned count;
	char icon;
};

