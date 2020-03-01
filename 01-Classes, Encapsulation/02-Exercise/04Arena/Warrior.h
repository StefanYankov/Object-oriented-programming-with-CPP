#pragma once
#include <string>
class Warrior
{
public:
	Warrior();
	Warrior(std::string, int, int, int);

	std::string GetName() const;
	void SetName(std::string);

	int GetHealth() const;
	void SetHealth(int);

	int GetAttackMax() const;
	void SetAttackMax(int);

	int GetBlockMax() const;
	void SetBlockMax(int);

	int Attack();
	int Block();

	std::string name;
	int health;
private:
	int attackMax;
	int blockMax;
};

