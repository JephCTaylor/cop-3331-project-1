#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "Dice.h"
#include "Histogram.h"

class GameStats {
 public:
  void DisplayDiceStats(int dice_amount_, int rolls, Dice &dice,
                        Histogram &histo);
  void CombineDiceRolls(Dice &dice1, Dice &dice2, Histogram &histo);

 private:
  void AddRollsToHisto(Dice &dice, Histogram &histo, int low_roll,
                       int high_roll);
};

#endif
