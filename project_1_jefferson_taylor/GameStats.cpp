#include "GameStats.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <string>

// aDie is rolled specified amount of times and values are Added to the
// histogram, the histogram will then Display the counts of all values and the
// graph
void GameStats::DisplayRollStats(int rolls, aDie &dice, Histogram &histo) {
  for (int i = 0; i < rolls; i++) {
    (int)dice;
  }
  histo.DisplayStats(Mode::Dice, dice.roll_log_, dice.GetLowestRoll(),
                     dice.GetHighestRoll());
}

void GameStats::DisplayTossStats(int plays, aCoin &coin, Histogram &histo) {
  for (int i = 0; i < plays; i++) {
    (std::string) coin;
  }
  histo.DisplayStats(Mode::Coin, coin.toss_log_, Heads, Tails);
}

// the rolls logs from aDie arguments are summed and displayed by the histo
void GameStats::SumDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo) {
  std::vector<int> temp_log;
  SwitchLargestDie(dice1, dice2);
  temp_log.resize(dice1.roll_log_.size(), 0);

  std::transform(dice1.roll_log_.begin(), dice1.roll_log_.end(),
                 dice2.roll_log_.begin(), temp_log.begin(), std::plus<int>());

  int low = dice1.GetLowestRoll() + dice2.GetLowestRoll();
  int high = dice1.GetHighestRoll() + dice2.GetHighestRoll();
  histo.DisplayStats(Mode::Dice, temp_log, low, high);
}

// the rolls logs from aDie arguments are multiplied and displayed by the histo
void GameStats::MultiplyDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo) {
  std::vector<int> temp_log;
  SwitchLargestDie(dice1, dice2);
  temp_log.resize(dice1.roll_log_.size(), 0);

  std::transform(dice1.roll_log_.begin(), dice1.roll_log_.end(),
                 dice2.roll_log_.begin(), temp_log.begin(),
                 std::multiplies<int>());

  int low = dice1.GetLowestRoll() * dice2.GetLowestRoll();
  int high = dice1.GetHighestRoll() * dice2.GetHighestRoll();
  histo.DisplayStats(Mode::Dice, temp_log, low, high);
}

// aDie with largest value range becomes dice1
void GameStats::SwitchLargestDie(aDie &dice1, aDie &dice2) {
  if (dice1.roll_log_.size() < dice2.roll_log_.size()) {
    std::swap(dice1, dice2);
  }
}
