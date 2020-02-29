#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "Dealer.h"
#include "Dice.h"
#include "Histogram.h"

class GameStats {
 public:
  void DisplayRollStats(int rolls, Dealer &dealer, Histogram &histo);
  void SumDiceRolls(Dice &dice1, Dice &dice2, Histogram &histo);
  void MultiplyDiceRolls(Dice &dice1, Dice &dice2, Histogram &histo);
  void SetupTempDealer(Dice &dice1, Dice &dice2, Dealer &dealer);
  void SwitchLargestDie(Dice &d1, Dice &d2);
  void DisplayStats(Histogram &histo, std::vector<int> list, int lower,
                        int upper);
};

#endif
