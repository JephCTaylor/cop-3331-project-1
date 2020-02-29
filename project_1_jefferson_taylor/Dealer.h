#ifndef DEALER_H
#define DEALER_H

#include <vector>

#include "aDie.h"

class Dealer {
 public:
  void AddDie(aDie* aDie);
  void ClearLogs();
  void ClearDice();
  int RollDice();
  int GetHighestRoll();
  int GetLowestRoll();

  std::vector<aDie*> dice_;
  std::vector<int> roll_log_;
};

#endif
