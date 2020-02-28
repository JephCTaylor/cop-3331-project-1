#ifndef DICE_H
#define DICE_H

#include <vector>

class Dice {
 public:
  Dice();
  // Dice(int dice_amount_);
  // Dice(int dice_amount, int dice_sides);
  int GetDiceAmount();
  void SetDiceAmount(int dice_amount_);
  int Roll();
  operator int();
  int GetLowestRoll();
  int GetHighestRoll();
  void SetDiceSides(int dice_sides);
  int GetDiceSides();

  std::vector<int> roll_log_;

 private:
  int dice_amount_{1};
  int dice_sides_{6};
  int lowest_roll_{1};
  int highest_roll_{6};

  void SetRollRange();
};

#endif
