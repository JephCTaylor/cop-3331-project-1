#ifndef DICE_H
#define DICE_H

class Dice
{
public:
	Dice();
	void setDiceAmount(int dice_amount);
	int Roll();
	int getLowestRoll();
	int getHighestRoll();

private:
	int dice_amount{ 1 };
	int lowest_roll{ 1 };
	int highest_roll{ 6 };

	void setRollRange();
};

#endif
