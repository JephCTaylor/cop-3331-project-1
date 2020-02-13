#ifndef DICE_H
#define DICE_H

class Dice
{
private:
	int dice_amount;
	int lowest_roll;
	int highest_roll;
	int roll_total;

public:
	Dice(int dice_amount);
	void setRollRange();
	int getDiceAmount();
	int Roll();
};

#endif
