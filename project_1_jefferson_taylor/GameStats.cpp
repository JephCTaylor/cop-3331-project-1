#include "GameStats.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>

// dice is rolled specified amount of times and values are Added to the
// histogram, the histogram will then Display the counts of all values and the
// graph
void GameStats::DisplayRollStats(int rolls, Dealer &dealer, Histogram &histo) {
  for (int i = 0; i < rolls; i++) {
    dealer.RollDice();
  }
  DisplayStats(histo, dealer.roll_log_, dealer.GetLowestRoll(),
               dealer.GetHighestRoll());
}

// the rolls logs from dice arguments are summed and displayed by the histo
void GameStats::SumDiceRolls(Dice &dice1, Dice &dice2, Histogram &histo) {
  Dealer deal_temp;
  SetupTempDealer(dice1, dice2, deal_temp);

  std::transform(dice1.roll_log_.begin(), dice1.roll_log_.end(),
                 dice2.roll_log_.begin(), deal_temp.roll_log_.begin(),
                 std::plus<int>());

  DisplayStats(histo, deal_temp.roll_log_, deal_temp.GetLowestRoll(),
               deal_temp.GetHighestRoll());
}

// the rolls logs from dice arguments are multiplied and displayed by the histo
void GameStats::MultiplyDiceRolls(Dice &dice1, Dice &dice2, Histogram &histo) {
  Dealer deal_temp;
  SetupTempDealer(dice1, dice2, deal_temp);

  std::transform(dice1.roll_log_.begin(), dice1.roll_log_.end(),
                 dice2.roll_log_.begin(), deal_temp.roll_log_.begin(),
                 std::multiplies<int>());

  int low = dice1.GetLowestRoll() * dice2.GetLowestRoll();
  int high = dice1.GetHighestRoll() * dice2.GetHighestRoll();
  DisplayStats(histo, deal_temp.roll_log_, low, high);
}

// organizes dice size, resizes dealer roll log, and adds dice to dealer
void GameStats::SetupTempDealer(Dice &dice1, Dice &dice2, Dealer &dealer) {
  SwitchLargestDie(dice1, dice2);
  dealer.roll_log_.resize(dice1.roll_log_.size(), 0);
  dealer.AddDie(&dice1);
  dealer.AddDie(&dice2);
}

// dice with largest value range becomes dice1
void GameStats::SwitchLargestDie(Dice &dice1, Dice &dice2) {
  if (dice1.roll_log_.size() < dice2.roll_log_.size()) {
    std::swap(dice1, dice2);
  }
}

// Takes the values from a vector and adds them to the histo object,
// then displays the histogram and frequency
void GameStats::DisplayStats(Histogram &histo, std::vector<int> list, int lower,
                             int upper) {
  histo.SetHistoRange(lower, upper);
  for (int x : list) {
    histo.AddValue(x);
  }
  histo.DisplayValueHisto();
}
