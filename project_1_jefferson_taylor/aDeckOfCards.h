#ifndef ADECKOFCARD_H
#define ADECKOFCARD_H

#include "aCard.h"

class aDeckOfCards {
 public:
  void ResetDeck();
  void DisplayHand() const;
  std::vector<Card> Draw(const int num_of_cards, const bool replacement);
  operator Card();

 private:
  Card DrawCard();
  bool IsDrawn(const Card &card);

  std::vector<Card> drawn_;
  std::vector<Card> hand_;
};

#endif  // !ADECKOFCARD_H
