#include <stdlib.h>
#include <iostream>
#include "Dice.h"
#include "Histogram.h"

int main()
{
	int user_seed;
	Dice dice;
	Dice dice2{ 2 };

	std::cout << "Enter a seed value for the dice rolls: " << std::endl;
	std::cin >> user_seed;

	srand(user_seed);

	Histogram dice_histogram{ dice.getLowestRoll(), dice.getHighestRoll(), 1 };
	std::cout << dice_histogram.getHistoSize() << std::endl;

	std::cout << dice.getDiceAmount() << " " << dice2.getDiceAmount() << std::endl;
	std::cout << dice.Roll() << " " << dice.Roll() << " " << dice.Roll() << std::endl;
	std::cout << dice2.Roll() << " " << dice2.Roll() << " " << dice2.Roll() << std::endl;
	dice.setDiceAmount(3);
	dice2.setDiceAmount(4);
	std::cout << dice.getDiceAmount() << " " << dice2.getDiceAmount() << std::endl;
	std::cout << dice.Roll() << " " << dice.Roll() << " " << dice.Roll() << std::endl;
	std::cout << dice2.Roll() << " " << dice2.Roll() << " " << dice2.Roll() << std::endl;
}
