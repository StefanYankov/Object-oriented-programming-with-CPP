#include <iostream>
#include <time.h>
#include "Warrior.h"
#include "Battle.h"

int main()
{
	srand(time(NULL));

	Warrior thor("Thor", 100, 30, 15);
	Warrior hulk("Hulk", 135, 25, 10);

	Battle::StartFight(thor, hulk);
}
