#include "Dealer.h"

#include <stdlib.h>

#include <iostream>

void Dealer::AddDie(aDie* aDie) { dice_.push_back(aDie); }

int Dealer::RollDice() {
  int total = 0;
  for (aDie* die : dice_) {
    // using the conversion operator, with a twist
    total += *(die);
  }
  roll_log_.push_back(total);
  return total;
}

std::string Dealer::TossCoin() {
  std::string toss = coin_;
  toss_log_.push_back(toss);
  return toss;
}

int Dealer::GetHighestRoll() {
  int roll = 0;
  for (aDie* die : dice_) {
    roll += die->GetHighestRoll();
  }
  return roll;
}

int Dealer::GetLowestRoll() {
  int roll = 0;
  for (aDie* die : dice_) {
    roll += die->GetLowestRoll();
  }
  return roll;
}

void Dealer::ClearLogs() {
  roll_log_.clear();
  toss_log_.clear();
}

void Dealer::ClearDice() { dice_.clear(); }
