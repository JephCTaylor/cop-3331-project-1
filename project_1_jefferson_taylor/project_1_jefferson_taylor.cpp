#include <stdlib.h>
#include <iostream>
#include "Dice.h"
#include "Histogram.h"
#include "GameStats.h"


int main()
{
	int user_seed, rolls;

	std::cout << "Enter a seed value for the dice rolls: " << std::endl;
	std::cin >> user_seed;
	std::cout << "Enter amount of rolls: " << std::endl;
	std::cin >> rolls;
	srand(user_seed);
	std::cout << std::endl;

	Dice dice;
	Histogram histo;
	GameStats stats;

	stats.displayDiceStats(1, rolls, dice, histo);
	stats.displayDiceStats(2, rolls, dice, histo);
	stats.displayDiceStats(3, rolls, dice, histo);
}
