#include <stdlib.h>
#include <iostream>
#include "Dice.h"
#include "Histogram.h"

int main()
{
	int user_seed;
	Dice dice;

	std::cout << "Enter a seed value for the dice rolls: " << std::endl;
	std::cin >> user_seed;

	srand(user_seed);

	Histogram dice_histogram{ dice.getLowestRoll(), dice.getHighestRoll(), 1 };
	for (int i = 0; i < 6000; i++) {
		dice_histogram.addValue(dice.Roll());
	}
	dice_histogram.displayHisto();
}
