#include <time.h>
#include <cstdlib>
#include "Dice.h"

class Dice
{
private:
	int dice_amount{ 1 };
	int roll_total{ 0 };

public:
	Dice(int dice_amount)
		: dice_amount(dice_amount)
	{}
};
