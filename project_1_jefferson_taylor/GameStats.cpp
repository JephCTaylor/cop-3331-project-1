#include "GameStats.h"

void GameStats::displayDiceStats(int dice_amount, int rolls, Dice dice, Histogram histo) {
	dice.setDiceAmount(dice_amount);
	histo.setHistoRange(dice.getLowestRoll(), dice.getHighestRoll(), 1);
	for (int i = 0; i < rolls; i++) {
		histo.addValue(dice.Roll());
	}
	histo.displayHisto();
}
