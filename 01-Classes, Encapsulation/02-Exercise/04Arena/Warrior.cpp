#include "Warrior.h"

Warrior::Warrior()
{
	name = "defaul warrior";
	health = 100;
	attackMax = 5;
	blockMax = 3;
}
Warrior::Warrior(std::string name, int health, int attackMax, int blockMax)
{
	this->name = name;
	this->health = health;
	this->attackMax = attackMax;
	this->blockMax = blockMax;
}

std::string Warrior::GetName() const
{
	return this->name;
}
void Warrior::SetName(std::string name)
{
	this->name = name;
}

int Warrior::GetHealth() const
{
	return health;
}
void Warrior::SetHealth(int health)
{
	this->health = health;
}

int Warrior::GetAttackMax() const
{
	return attackMax;
}
void Warrior::SetAttackMax(int attackMax)
{
	this->attackMax = attackMax;
}

int Warrior::GetBlockMax() const
{
	return blockMax;
}
void Warrior::SetBlockMax(int blockMax)
{
	this->blockMax = blockMax;
}

int Warrior::Attack()
{
	return std::rand() % this->attackMax;
}
int Warrior::Block()
{
	return std::rand() % this->blockMax;
}
