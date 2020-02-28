#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "Dealer.h"
#include "Dice.h"
#include "Histogram.h"

class GameStats {
 public:
  void DisplayRollStats(int rolls, Dealer &dealer, Histogram &histo);
  void CombineDiceRolls(Dice &dice1, Dice &dice2, Histogram &histo);
};

#endif
