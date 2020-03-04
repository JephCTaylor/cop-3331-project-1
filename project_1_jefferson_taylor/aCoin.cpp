#include "aCoin.h"

#include <stdlib.h>

#include <iostream>

// simulates the toss of a coin landing on either heads or tails
// returns a string of H for heads or T for tails
std::string aCoin::Toss() {
  switch (rand() % COIN_SIDES) {
    case Heads:
      toss_log_.push_back(Heads);
      return "H";
    case Tails:
      toss_log_.push_back(Tails);
      return "T";
    default:
      std::cerr << "aCoin::Toss() didn't pick heads or tails.";
      break;
  }
}

aCoin::operator std::string() { return Toss(); }
