#ifndef DICE_H
#define DICE_H

#include <vector>

class Dice
{
public:
	Dice();
	Dice(int dice_amount);
	int getDiceAmount();
	void setDiceAmount(int dice_amount);
	int Roll();
	int getLowestRoll();
	int getHighestRoll();
	std::vector<int> roll_log;

private:
	int dice_amount{ 1 };
	int lowest_roll{ 1 };
	int highest_roll{ 6 };

	void setRollRange();
};

#endif
