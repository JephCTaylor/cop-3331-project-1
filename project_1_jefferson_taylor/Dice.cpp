#include <stdlib.h>
#include <time.h>
#include "Dice.h"

Dice::Dice() {}

// custom constructor for dice that sets up roll range
Dice::Dice(int dice_amount) 
	: dice_amount(dice_amount)
{
	setRollRange();
}

// changes amount of dice to given argument value and changes roll range
void Dice::setDiceAmount(int dice_amount) {
	this->dice_amount = dice_amount;
	setRollRange();
}

// sets the range value that the dice can be
void Dice::setRollRange() {
	lowest_roll = dice_amount;
	highest_roll = dice_amount * 6;
}

// returns a roll value for the given amount of dice
int Dice::Roll() {
	return rand() % (highest_roll - lowest_roll + 1) + lowest_roll;
}

//temp function, delete later
int Dice::getDiceAmount() {
	return dice_amount;
}

int Dice::getLowestRoll() {
	return lowest_roll;
}

int Dice::getHighestRoll() {
	return highest_roll;
}
