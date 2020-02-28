#include "Dice.h"

#include <stdlib.h>

// default constructor with some logic
Dice::Dice() { SetRollRange(); }

// delegating construction isn't working, dont really wanna figure out why right
// now
// Dice::Dice(int dice_amount) : Dice(dice_amount, dice_sides_) {
// SetRollRange(); }
//
//// sets the roll range for the dice when initialized
// Dice::Dice(int dice_amount, int dice_sides)
//    : dice_amount_(dice_amount), dice_sides_(dice_sides) {
//  SetRollRange();
//}

int Dice::GetDiceAmount() { return dice_amount_; }

// changes amount of dice to given argument value and changes roll range
void Dice::SetDiceAmount(int dice_amount) {
  dice_amount_ = dice_amount;
  SetRollRange();
}

int Dice::GetDiceSides() { return dice_sides_; }

void Dice::SetDiceSides(int dice_sides) {
  dice_sides_ = dice_sides;
  SetRollRange();
}

// Sets the maximum and minimum Combined roll that the specified amount of dice
// can be
void Dice::SetRollRange() {
  lowest_roll_ = dice_amount_;
  highest_roll_ = dice_amount_ * dice_sides_;
}

// returns a roll value for the given amount of dice, and stores the value
// in the roll_log_ of the dice object
int Dice::Roll() {
  int roll_total = 0;
  for (int i = 0; i < dice_amount_; i++) {
    roll_total += rand() % dice_sides_ + 1;
  }
  roll_log_.push_back(roll_total);
  return roll_total;
}

int Dice::GetLowestRoll() { return lowest_roll_; }

int Dice::GetHighestRoll() { return highest_roll_; }

// example of how to return a vector by value
// std::vector<int> Dice::GetRollLog() {
//    std::vector<int> result = roll_log_;
//    return result;
//}
