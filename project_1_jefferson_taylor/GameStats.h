#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "Histogram.h"
#include "aCoin.h"
#include "aDeckOfCards.h"
#include "aDie.h"

class GameStats {
 public:
  void DisplayPokerHands(aDeckOfCards &deck, const int hands, const int cards) const;
  void DisplayRollStats(int rolls, aDie &dice, Histogram &histo) const;
  void DisplayTossStats(int play_count, aCoin &coin, Histogram &histo) const;
  void SumDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo) const;
  void MultiplyDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo) const;
  void SwitchLargestDie(aDie &d1, aDie &d2) const;
};

#endif
