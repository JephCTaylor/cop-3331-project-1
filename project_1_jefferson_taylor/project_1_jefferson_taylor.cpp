#include <stdlib.h>
#include <iostream>
#include "Dice.h"
#include "Histogram.h"
#include "GameStats.h"


int main()
{
	int user_seed;

	std::cout << "Enter a seed value for the dice rolls: " << std::endl;
	std::cin >> user_seed;
	std::cout << std::endl;

	srand(user_seed);

	Dice dice;
	Histogram histo;
	GameStats stats;

	stats.displayDiceStats(1, 6000, dice, histo);
	stats.displayDiceStats(2, 6000, dice, histo);
	stats.displayDiceStats(3, 6000, dice, histo);
}
