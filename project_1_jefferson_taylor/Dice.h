#ifndef DICE_H
#define DICE_H

class Dice
{
private:
	int dice_amount;
	int lowest_roll;
	int highest_roll;

public:
	//Dice();
	Dice(int dice_amount);
	//Dice(int dice_amount, long int seed);
	void setDiceAmount(int dice_amount);
	void setRollRange();
	int getDiceAmount();
	int Roll();
};

#endif
