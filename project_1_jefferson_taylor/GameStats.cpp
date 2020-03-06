#include "GameStats.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <string>

// deals out a cards to different players and prints out all the hands dealt
// displays dealing out hands with and without replacement of drawn cards
void GameStats::DisplayPokerHands(aDeckOfCards &deck, const int hands,
                                  const int cards) const {
  std::cout << hands << " Hands with replacement of cards:" << std::endl;
  for (int i = 0; i < hands; i++) {
    std::cout << "Hand " << i + 1 << ": ";
    deck.Draw(cards, true);
    deck.DisplayHand();
  }
  std::cout << std::endl;

  deck.ResetDeck();

  std::cout << hands << " Hands without replacement of cards:" << std::endl;
  for (int i = 0; i < hands; i++) {
    std::cout << "Hand " << i + 1 << ": ";
    deck.Draw(cards, false);
    deck.DisplayHand();
  }
  std::cout << std::endl;
}

// aDie is rolled specified amount of times and values are Added to the
// histogram, the histogram will then Display the counts of all values and the
// graph
void GameStats::DisplayRollStats(const int rolls, aDie &dice,
                                 Histogram &histo) const {
  for (int i = 0; i < rolls; i++) {
    (int)dice;
  }
  const int lower_bound = dice.GetLowestRoll();
  const int upper_bound = dice.GetHighestRoll();
  histo.DisplayStats(Mode::Dice, dice.roll_log_, lower_bound, upper_bound);
}

// simulates the flipping a coin a specified amount of times and prints the
// frequency of heads or tails as well as a histogram
void GameStats::DisplayTossStats(const int plays, aCoin &coin,
                                 Histogram &histo) const {
  for (int i = 0; i < plays; i++) {
    (std::string) coin;
  }
  const int lower_bound = static_cast<int>(Side::Heads);
  const int upper_bound = static_cast<int>(Side::Tails);
  histo.DisplayStats(Mode::Coin, coin.toss_log_, lower_bound, upper_bound);
}

// the rolls logs from aDie arguments are summed and displayed by the histo
void GameStats::SumDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo) const {
  std::vector<int> temp_log;
  SwitchLargestDie(dice1, dice2);
  temp_log.resize(dice1.roll_log_.size(), 0);

  std::transform(dice1.roll_log_.begin(), dice1.roll_log_.end(),
                 dice2.roll_log_.begin(), temp_log.begin(), std::plus<int>());

  const int lower_bound = dice1.GetLowestRoll() + dice2.GetLowestRoll();
  const int upper_bound = dice1.GetHighestRoll() + dice2.GetHighestRoll();
  histo.DisplayStats(Mode::Dice, temp_log, lower_bound, upper_bound);
}

// the rolls logs from aDie arguments are multiplied and displayed by the histo
void GameStats::MultiplyDiceRolls(aDie &dice1, aDie &dice2,
                                  Histogram &histo) const {
  std::vector<int> temp_log;
  SwitchLargestDie(dice1, dice2);
  temp_log.resize(dice1.roll_log_.size(), 0);

  std::transform(dice1.roll_log_.begin(), dice1.roll_log_.end(),
                 dice2.roll_log_.begin(), temp_log.begin(),
                 std::multiplies<int>());

  const int lower_bound = dice1.GetLowestRoll() * dice2.GetLowestRoll();
  const int upper_bound = dice1.GetHighestRoll() * dice2.GetHighestRoll();
  histo.DisplayStats(Mode::Dice, temp_log, lower_bound, upper_bound);
}

// aDie with largest value range becomes dice1
void GameStats::SwitchLargestDie(aDie &dice1, aDie &dice2) const {
  if (dice1.roll_log_.size() < dice2.roll_log_.size()) {
    std::swap(dice1, dice2);
  }
}
