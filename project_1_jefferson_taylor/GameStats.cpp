#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "GameStats.h"

//dice is rolled specified amount of times and values are added to the histogram,
//the histogram will then display the counts of all values and the graph
void GameStats::displayDiceStats(int dice_amount, int rolls, Dice& dice, Histogram& histo) {
	dice.setDiceAmount(dice_amount);
	for (int i = 0; i < rolls; i++) {
		dice.Roll();
	}
	addRollsToHisto(dice, histo);
	histo.displayValueHisto();
}

//combines dice rolls sequentially, as if the dice were rolled with the values
//totaled together. It's then added to a histogram class so the data can be displayed
//The dice must have been rolled the same amount of times for this function to work
void GameStats::combineDiceRolls(Dice& dice1, Dice& dice2, Histogram& histo) {
	std::vector<int> temp_log(dice1.roll_log.size(), 0);
	Dice dice_temp(dice1.getDiceAmount() + dice2.getDiceAmount());
	
	//iteratates from beginning to end of both dice roll logs and puts the combined 
	//values into the temp_log vector
	std::transform (dice1.roll_log.begin(), dice1.roll_log.end(), 
					dice2.roll_log.begin(), temp_log.begin(), std::plus<int>());

	dice_temp.roll_log = temp_log;
	addRollsToHisto(dice_temp, histo);
	histo.displayValueHisto();
}

//the roll_log from the dice argument will be added to the histo object
//so that the data can be displayed
void GameStats::addRollsToHisto(Dice& dice, Histogram& histo) {
	histo.setHistoRange(dice.getLowestRoll(), dice.getHighestRoll());
	for (int x : dice.roll_log) {
		histo.addValue(x);
	}
}
