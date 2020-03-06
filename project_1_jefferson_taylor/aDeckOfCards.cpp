#include "aDeckOfCards.h"

void aDeckOfCards::DisplayHand() const {
  for (Card card : hand) {
    card.DisplayCard();
  }
  std::cout << std::endl;
}

std::vector<Card> aDeckOfCards::Draw(const int num_of_cards,
                                     const bool replacement) {
  hand.clear();
  Card card;

  while (hand.size() < num_of_cards) {
    card = DrawCard();
    if (replacement && IsDuplicate(card)) {
      continue;
    }
    hand.push_back(card);
  }
  return hand;
}

aDeckOfCards::operator Card() { return DrawCard(); }

Card aDeckOfCards::DrawCard() {
  Card card{brands.at(rand() % kBrands), suits.at(rand() % kSuits)};
  return card;
}

bool aDeckOfCards::IsDuplicate(const Card &card) const {
  for (Card hand_card : hand) {
    if (hand_card.brand == card.brand && hand_card.suit == card.suit) {
      return true;
    }
  }
  return false;
}
