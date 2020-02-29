#include "Dealer.h"

#include <stdlib.h>

#include <iostream>

void Dealer::AddDie(aDie* aDie) { dice_.push_back(aDie); }

void Dealer::ClearLogs() { roll_log_.clear(); }

void Dealer::ClearDice() { dice_.clear(); }

int Dealer::RollDice() {
  int total = 0;
  for (aDie* aDie : dice_) {
    // using the conversion operator, with a twist
    total += *(aDie);
  }
  roll_log_.push_back(total);
  return total;
}

int Dealer::GetHighestRoll() {
  int roll = 0;
  for (aDie* aDie : dice_) {
    roll += aDie->GetHighestRoll();
  }
  return roll;
}

int Dealer::GetLowestRoll() {
  int roll = 0;
  for (aDie* aDie : dice_) {
    roll += aDie->GetLowestRoll();
  }
  return roll;
}
