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

	Dice dice1, dice2;
	Histogram histo1, histo2, histo3;
	GameStats stats;

	std::cout << "Roll stats from first die:" << std::endl;
	stats.displayDiceStats(1, rolls, dice1, histo1);
	std::cout << "Roll stats from second die:" << std::endl;
	stats.displayDiceStats(1, rolls, dice2, histo2);
	std::cout << "Roll stats from first and second die combined:" << std::endl;
	stats.combineDiceRolls(dice1, dice2, histo3);
}
