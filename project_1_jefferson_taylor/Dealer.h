#ifndef DEALER_H
#define DEALER_H

#include <string>
#include <vector>

#include "aCoin.h"
#include "aDie.h"

class Dealer {
 public:
  void AddDie(aDie* aDie);
  int RollDice();
  std::string TossCoin();
  int GetHighestRoll();
  int GetLowestRoll();
  void ClearLogs();
  void ClearDice();

  std::vector<int> roll_log_;
  std::vector<std::string> toss_log_;
  aCoin coin_;

 private:
  std::vector<aDie*> dice_;
};

#endif
