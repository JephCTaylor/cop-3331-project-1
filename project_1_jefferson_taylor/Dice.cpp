#include <stdlib.h>
#include "Dice.h"

Dice::Dice() {}

// custom constructor thats initialized with specified dice count
Dice::Dice(int dice_amount)
	: dice_amount(dice_amount)
{
	setRollRange();
}

int Dice::getDiceAmount() {
	return dice_amount;
}

// changes amount of dice to given argument value and changes roll range
void Dice::setDiceAmount(int dice_amount) {
	this->dice_amount = dice_amount;
	setRollRange();
}

// sets the maximum and minimum combined roll that the specified amount of dice can be
void Dice::setRollRange() {
	lowest_roll = dice_amount;
	highest_roll = dice_amount * 6;
}

// returns a roll value for the given amount of dice
int Dice::Roll() {
	int roll_total = 0;
	for (int i = 0; i < dice_amount; i++) {
		roll_total += rand() % 6 + 1;
	}
	roll_log.push_back(roll_total);
	return roll_total;
}

int Dice::getLowestRoll() {
	return lowest_roll;
}

int Dice::getHighestRoll() {
	return highest_roll;
}

// example of how to return a vector by value 
//std::vector<int> Dice::getRollLog() {
//    std::vector<int> result = roll_log;
//    return result;
//}
