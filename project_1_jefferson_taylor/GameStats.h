#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "Dealer.h"
#include "Histogram.h"
#include "aCoin.h"
#include "aDie.h"

class GameStats {
 public:
  void DisplayRollStats(int rolls, aDie &dice, Histogram &histo);
  void DisplayTossStats(int play_count, aCoin &coin, Histogram &histo);
  void SumDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo);
  void MultiplyDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo);
  void SwitchLargestDie(aDie &d1, aDie &d2);
};

#endif
