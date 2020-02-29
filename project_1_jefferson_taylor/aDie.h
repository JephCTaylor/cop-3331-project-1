#ifndef DICE_H
#define DICE_H

#include <vector>

class aDie {
 public:
  aDie();
  int Roll();
  operator int();
  void SetDiceAmount(int dice_amount_);
  void SetDiceSides(int dice_sides);

  int GetDiceAmount() const;
  int GetDiceSides() const;
  int GetLowestRoll() const;
  int GetHighestRoll() const;

  std::vector<int> roll_log_;

 private:
  int dice_amount_{1};
  int dice_sides_{6};
  int lowest_roll_{1};
  int highest_roll_{6};

  void SetRollRange();
};

#endif
