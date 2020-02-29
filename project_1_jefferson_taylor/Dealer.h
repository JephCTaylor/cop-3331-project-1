#ifndef DEALER_H
#define DEALER_H

#include <vector>

#include "Dice.h"

class Dealer {
 public:
  void AddDie(Dice* dice);
  void ClearRollLog();
  void ClearDice();
  int RollDice();
  int GetHighestRoll();
  int GetLowestRoll();

  std::vector<Dice*> dice_;
  std::vector<int> roll_log_;
};

#endif
