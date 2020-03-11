#ifndef ADECKOFCARD_H
#define ADECKOFCARD_H

#include "aCard.h"

class aDeckOfCards {
 public:
  void ResetDeck();
  void DisplayHand() const;
  std::vector<aCard> Draw(const int num_of_cards, const bool replacement);
  operator aCard();

 private:
  aCard DrawCard();
  bool IsDrawn(const aCard &card);

  std::vector<aCard> drawn_;
  std::vector<aCard> hand_;
};

#endif  // !ADECKOFCARD_H
