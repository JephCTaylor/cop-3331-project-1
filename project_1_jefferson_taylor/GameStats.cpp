#include "GameStats.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>

// dice is rolled specified amount of times and values are Added to the
// histogram, the histogram will then Display the counts of all values and the
// graph
void GameStats::DisplayDiceStats(int dice_amount_, int rolls, Dice &dice,
                                 Histogram &histo) {
  dice.SetDiceAmount(dice_amount_);
  for (int i = 0; i < rolls; i++) {
    dice.Roll();
  }
  AddRollsToHisto(dice, histo);
  histo.DisplayValueHisto();
}

// Combines dice rolls sequentially, as if the dice were rolled with the values
// totaled toGether. It's then Added to a histogram class so the data can be
// Displayed The dice must have been rolled the same amount of times for this
// function to work might want to Add a try catch later
void GameStats::CombineDiceRolls(Dice &dice1, Dice &dice2, Histogram &histo) {
  std::vector<int> temp_log(dice1.roll_log_.size(), 0);
  Dice dice_temp(dice1.GetDiceAmount() + dice2.GetDiceAmount());

  // iteratates from beginning to end of both dice roll logs and puts the
  // Combined values into the temp_log vector
  std::transform(dice1.roll_log_.begin(), dice1.roll_log_.end(),
                 dice2.roll_log_.begin(), temp_log.begin(), std::plus<int>());

  dice_temp.roll_log_ = temp_log;
  AddRollsToHisto(dice_temp, histo);
  histo.DisplayValueHisto();
}

// the roll_log_ from the dice argument will be Added to the histo object
// so that the data can be Displayed
void GameStats::AddRollsToHisto(Dice &dice, Histogram &histo) {
  histo.SetHistoRange(dice.GetLowestRoll(), dice.GetHighestRoll());
  for (int x : dice.roll_log_) {
    histo.AddValue(x);
  }
}
