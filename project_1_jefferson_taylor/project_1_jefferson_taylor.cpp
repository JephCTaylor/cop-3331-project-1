// project_1_jefferson_taylor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
