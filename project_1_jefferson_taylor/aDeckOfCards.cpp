#include "aDeckOfCards.h"

// clears the drawn and hand vector so that the deck has all cards available
void aDeckOfCards::ResetDeck() {
  drawn_.clear();
  hand_.clear();
}

// displays all the cards in the object's hand vector
void aDeckOfCards::DisplayHand() const {
  for (aCard card : hand_) {
    card.DisplayCard();
  }
  std::cout << std::endl;
}

// returns a vector of cards, if replace_card is true,
// then it will continue to randomly select a card until
// one is found that has not been drawn
std::vector<aCard> aDeckOfCards::Draw(const int num_of_cards,
                                      const bool replace_card) {
  hand_.clear();

  while (hand_.size() < num_of_cards) {
    aCard card = DrawCard();
    if (!replace_card && IsDrawn(card)) {
      continue;
    }
    hand_.push_back(card);
  }
  return hand_;
}

aDeckOfCards::operator aCard() { return DrawCard(); }

// generates a single card struct with a brand a suit
aCard aDeckOfCards::DrawCard() {
  return {static_cast<Brand>(rand() % kBrands),
          static_cast<Suit>(rand() % kSuits)};
}

// checks if the card has already been drawn, if not, the card
// will be added to list of drawn cards
bool aDeckOfCards::IsDrawn(const aCard &card) {
  bool isDrawn = false;

  for (aCard drawn_card : drawn_) {
    if (drawn_card.brand == card.brand && drawn_card.suit == card.suit) {
      isDrawn = true;
    }
  }
  if (!isDrawn) {
    drawn_.push_back(card);
  }
  return isDrawn;
}