#include <stdlib.h>
#include <iostream>
#include "Dice.h"
#include "Histogram.h"

void getDiceStats(int dice_amount, int rolls, Dice dice, Histogram histo) {
	dice.setDiceAmount(dice_amount);
	histo.setHistoRange(dice.getLowestRoll(), dice.getHighestRoll(), 1);
	for (int i = 0; i < 6000; i++) {
		histo.addValue(dice.Roll());
	}
	histo.displayHisto();
}

int main()
{
	int user_seed;

	std::cout << "Enter a seed value for the dice rolls: " << std::endl;
	std::cin >> user_seed;
	std::cout << std::endl;

	srand(user_seed);

	Dice dice;
	Histogram dice_histogram;

	getDiceStats(1, 6000, dice, dice_histogram);
	getDiceStats(2, 6000, dice, dice_histogram);
	getDiceStats(3, 6000, dice, dice_histogram);
}
