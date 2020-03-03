#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "Dealer.h"
#include "Histogram.h"
#include "aCoin.h"
#include "aDie.h"

class GameStats {
 public:
  void DisplayRollStats(int rolls, Dealer &dealer, Histogram &histo);
  void DisplayTossStats(int play_count, Dealer &dealer, Histogram &histo);
  void SumDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo);
  void MultiplyDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo);
  void SetupTempDealer(aDie &dice1, aDie &dice2, Dealer &dealer);
  void SwitchLargestDie(aDie &d1, aDie &d2);
  void DisplayStats(Histogram &histo, std::vector<int> list, int lower,
                    int upper);
};

#endif
