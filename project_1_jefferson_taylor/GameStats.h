#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <functional>

#include "Histogram.h"
#include "aCoin.h"
#include "aDeckOfCards.h"
#include "aDie.h"

class GameStats {
 public:
  void DealHands(aDeckOfCards &deck, const int hands, const int cards,
                 const bool replace_cards) const;
  void DisplayRollStats(const int rolls, aDie &dice, Histogram &histo) const;
  void DisplayTossStats(const int play_count, aCoin &coin,
                        Histogram &histo) const;
  void CombineDiceRolls(aDie &dice1, aDie &dice2, Histogram &histo,
                        const std::function<int(int, int)> &func) const;
  void SwitchLargestDie(aDie &d1, aDie &d2) const;
};

#endif
