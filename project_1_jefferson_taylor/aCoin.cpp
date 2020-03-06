#include "aCoin.h"

#include <stdlib.h>

#include <iostream>

aCoin::operator std::string() { return Toss(); }

// simulates the toss of a coin landing on either heads or tails
// returns a string of H for heads or T for tails
std::string aCoin::Toss() {
  switch (static_cast<Side>(rand() % kCoinSides)) {
    case Side::Heads:
      toss_log_.push_back(static_cast<int>(Side::Heads));
      return "H";
    case Side::Tails:
      toss_log_.push_back(static_cast<int>(Side::Tails));
      return "T";
    default:
      std::cerr << "aCoin::Toss() didn't pick heads or tails.";
      break;
  }
}
