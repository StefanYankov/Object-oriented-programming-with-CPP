#pragma once
#include "Warrior.h"
#include <iostream>
class Battle
{
public:
	static void StartFight(Warrior& warrior1, Warrior& warrior2)
	{
		while (true)
		{
			if (Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0)
			{
				std::cout << "Game Over" << std::endl;
				break;
			}
			if (Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0)
			{
				std::cout << "Game Over" << std::endl;
				break;
			}
		}
	}

	static std::string GetAttackResult(Warrior& warriorA, Warrior& warriorB)
	{
		int warriorAAttackAmt = warriorA.Attack();
		int warriorBBlockAmt = warriorB.Block();
		int damageToWarriorB = ceil(warriorAAttackAmt - warriorBBlockAmt);
		damageToWarriorB = (damageToWarriorB <= 0) ? 0 : damageToWarriorB;
		warriorB.health = warriorB.health - damageToWarriorB;

		printf("%s attacks %s and deals %d damage\n", warriorA.name.c_str(), warriorB.name.c_str(), damageToWarriorB);

		printf("%s is down to %d health\n", warriorB.name.c_str(), warriorB.health);

		if (warriorB.health <= 0)
		{
			printf("%s has died and %s is victorious\n", warriorB.name.c_str(), warriorA.name.c_str());
			return "Game Over";
		}
		else
		{
			return "Figth again";
		}

	}
};

