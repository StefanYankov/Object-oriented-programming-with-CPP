#pragma once
class Human
{
private:
	char* name;
	char* familyName;
	bool hasYChromosome;
	bool hasBrother;

public:
	Human();
	Human(char* name, char* familyName, bool hasYChromosome, bool hasBrother = false);
	~Human();

	char* GetName() const;
	void SetName(char* name);
	char* GetFamilyName() const;
	void SetFamilyName(char* familyName);
	bool IsHasYChromosome() const;
	void SetHasYChromosome(bool hasYChromosome);
	bool IsHasBrother() const;
	void SetHasBrother(bool hasBrother);

	Human& operator+(const Human& male);
};

