#include "aDie.h"

#include <stdlib.h>

// default constructor with some logic
aDie::aDie() { SetRollRange(); }

// returns a roll value for the given amount of aDie, and stores the value
// in the roll_log_ of the aDie object
int aDie::Roll() {
  int roll_total = 0;
  for (int i = 0; i < dice_amount_; i++) {
    roll_total += rand() % dice_sides_ + 1;
  }
  roll_log_.push_back(roll_total);
  return roll_total;
}

aDie::operator int() { return Roll(); }

// changes amount of aDie to given argument value and changes roll range
void aDie::SetDiceAmount(int dice_amount) {
  dice_amount_ = dice_amount;
  SetRollRange();
}

void aDie::SetDiceSides(int dice_sides) {
  dice_sides_ = dice_sides;
  SetRollRange();
}

// Sets the maximum and minimum Combined roll that the specified amount of aDie
// can be
void aDie::SetRollRange() {
  lowest_roll_ = dice_amount_;
  highest_roll_ = dice_amount_ * dice_sides_;
}

int aDie::GetDiceAmount() const { return dice_amount_; }

int aDie::GetDiceSides() const { return dice_sides_; }

int aDie::GetLowestRoll() const { return lowest_roll_; }

int aDie::GetHighestRoll() const { return highest_roll_; }

// example of how to return a vector by value
// std::vector<int> aDie::GetRollLog() {
//    std::vector<int> result = roll_log_;
//    return result;
//}
