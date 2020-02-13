#include <stdlib.h>
#include <time.h>
#include "Dice.h"

int dice_amount{ 1 };
int lowest_roll{ 1 };
int highest_roll{ 6 };
int roll_total{ 0 };

Dice::Dice(int dice_amount) 
	: dice_amount(dice_amount)
{
	setRollRange();
}

void Dice::setRollRange() {
	lowest_roll = dice_amount;
	highest_roll = dice_amount * 6;
}

int Dice::Roll() {
	return rand() % (highest_roll - lowest_roll + 1) + lowest_roll;
}

//temp function, delete later
int Dice::getDiceAmount() {
	return dice_amount;
}
