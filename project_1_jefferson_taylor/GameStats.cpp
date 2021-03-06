#include "GameStats.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <string>

// deals out a cards to different players and prints out all the hands dealt
void GameStats::DealHands(aDeckOfCards &deck, const int hands, const int cards,
                          const bool replace_cards) const {
  std::vector<aCard> hand;
  for (int i = 0; i < hands; i++) {
    std::cout << "Hand " << i + 1 << ": ";
    hand = deck.Draw(cards, replace_cards);
    deck.DisplayHand();
  }
  std::cout << std::endl;
}

// aDie is rolled specified amount of times and values are Added to the
// histogram, the histogram will then Display the counts of all values and the
// graph
void GameStats::DisplayRollStats(const int rolls, aDie &dice,
                                 Histogram &histo) const {
  int dice_roll;
  for (int i = 0; i < rolls; i++) {
    dice_roll = dice;
  }
  histo.DisplayStats(Mode::Dice, dice.roll_log_);
}

// simulates the flipping a coin a specified amount of times and prints the
// frequency of heads or tails as well as a histogram
void GameStats::DisplayTossStats(const int plays, aCoin &coin,
                                 Histogram &histo) const {
  std::string coin_result;
  for (int i = 0; i < plays; i++) {
    coin_result = coin;
  }
  histo.DisplayStats(Mode::Coin, coin.toss_log_);
}

// the rolls logs from aDie arguments are combined by the func argument
void GameStats::CombineDiceRolls(
    aDie &dice1, aDie &dice2, Histogram &histo,
    const std::function<int(int, int)> &func) const {
  std::vector<int> temp_log;
  SwitchLargestDie(dice1, dice2);
  temp_log.resize(dice1.roll_log_.size(), 0);

  std::transform(dice1.roll_log_.begin(), dice1.roll_log_.end(),
                 dice2.roll_log_.begin(), temp_log.begin(), func);

  histo.DisplayStats(Mode::Dice, temp_log);
}

// aDie with largest value range becomes dice1 so that transform works
void GameStats::SwitchLargestDie(aDie &dice1, aDie &dice2) const {
  if (dice1.roll_log_.size() < dice2.roll_log_.size()) {
    std::swap(dice1, dice2);
  }
}
