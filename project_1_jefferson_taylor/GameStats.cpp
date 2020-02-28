#include "GameStats.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>

// dice is rolled specified amount of times and values are Added to the
// histogram, the histogram will then Display the counts of all values and the
// graph
void GameStats::DisplayRollStats(int rolls, Dealer &dealer, Histogram &histo) {
  histo.SetHistoRange(dealer.GetLowestRoll(), dealer.GetHighestRoll());
  for (int i = 0; i < rolls; i++) {
    histo.AddValue(dealer.RollDice());
  }
  histo.DisplayValueHisto();
}

// Combines dice rolls sequentially, as if the dice were rolled with the values
// totaled toGether. It's then Added to a histogram class so the data can be
// Displayed The dice must have been rolled the same amount of times for this
// function to work might want to Add a try catch later
void GameStats::CombineDiceRolls(Dice &dice1, Dice &dice2, Histogram &histo) {
  if (dice1.roll_log_.size() < dice2.roll_log_.size()) {
    // dice with largest range becomes dice1
    std::swap(dice1, dice2);
  }
  std::vector<int> temp_log(dice1.roll_log_.size(), 0);
  Dealer deal_temp;
  deal_temp.AddDie(&dice1);
  deal_temp.AddDie(&dice2);

  // iteratates from beginning to end of both dice roll logs and puts the
  // Combined values into the deal_temp.roll_log_ vector
  std::transform(dice1.roll_log_.begin(), dice1.roll_log_.end(),
                 dice2.roll_log_.begin(), temp_log.begin(), std::plus<int>());

  histo.SetHistoRange(deal_temp.GetLowestRoll(), deal_temp.GetHighestRoll());
  for (int x : temp_log) {
    histo.AddValue(x);
  }
  histo.DisplayValueHisto();
}
