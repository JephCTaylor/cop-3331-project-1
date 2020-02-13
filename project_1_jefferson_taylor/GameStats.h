#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "Dice.h"
#include "Histogram.h"

class GameStats
{
public:
	void displayDiceStats(int dice_amount, int rolls, Dice dice, Histogram histo);
};

#endif
