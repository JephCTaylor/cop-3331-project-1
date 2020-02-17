#ifndef DICE_H
#define DICE_H

#include <vector>

class Dice {
 public:
  Dice();
  Dice(int dice_amount_);
  int GetDiceAmount();
  void SetDiceAmount(int dice_amount_);
  int Roll();
  int GetLowestRoll();
  int GetHighestRoll();
  std::vector<int> roll_log_;

 private:
  int dice_amount_{1};
  int dice_sides_{6};
  int lowest_roll_{1};
  int highest_roll_{6};

  void SetRollRange();
};

#endif
