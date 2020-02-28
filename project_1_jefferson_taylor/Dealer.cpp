#include "Dealer.h"

#include <stdlib.h>

#include <iostream>

void Dealer::AddDie(Dice* dice) { dice_.push_back(dice); }

// Clears the roll log and dice vectors from the dealer object
void Dealer::ClearDealer() {
  ClearRollLog();
  ClearDice();
}

void Dealer::ClearRollLog() { roll_log_.clear(); }

void Dealer::ClearDice() { dice_.clear(); }

int Dealer::RollDice() {
  int total = 0;

  for (Dice* dice : dice_) {
    total += dice->Roll();
  }
  roll_log_.push_back(total);
  return total;
}

int Dealer::GetHighestRoll() {
  int roll = 0;

  for (Dice* dice : dice_) {
    roll += dice->GetHighestRoll();
  }
  return roll;
}

int Dealer::GetLowestRoll() {
  int roll = 0;

  for (Dice* dice : dice_) {
    roll += dice->GetLowestRoll();
  }
  return roll;
}
