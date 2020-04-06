#pragma once
class Element
{
private:
	char type;
public:
	Element();
	Element(char);

	char GetType() const;
	void SetType(char);
};

