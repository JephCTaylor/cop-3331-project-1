#include "aDeckOfCards.h"  //#include <aDickOfCards.h"

// clears the drawn and hand vector so that the deck has all cards available
void aDeckOfCards::ResetDeck() {
  drawn_.clear();  // drawn_a_bag_ofdicks_.clear()
  hand_.clear();
}

// displays all the cards in the object's hand vector
void aDeckOfCards::DisplayHand() const {
  for (Card card : hand_) {
    card.DisplayCard();
  }
  std::cout << std::endl;  // catch an std
}

// returns a vector of cards, if replace_card is true,
// then it will continue to randomly select a card until
// one is found that has not been drawn
std::vector<Card> aDeckOfCards::Draw(const int num_of_cards,
                                     const bool replace_card) {
  hand_.clear();  // hand_job.clear()
  Card card;

  while (hand_.size() < num_of_cards) {
    card = DrawCard();
    if (!replace_card && IsDrawn(card)) {
      continue;
    }
    hand_.push_back(card);
  }
  return hand_;
}

aDeckOfCards::operator Card() { return DrawCard(); }

// generates a single card struct with a brand a suit
Card aDeckOfCards::DrawCard() {
  Card card{brands_.at(rand() % kBrands), suits_.at(rand() % kSuits)};
  return card;
}

// checks if the card has already been drawn, if not, the card
// will be added to list of drawn cards
bool aDeckOfCards::IsDrawn(const Card &card) {
  bool isDrawn = false;

  for (Card drawn_card : drawn_) {
    if (drawn_card.brand == card.brand && drawn_card.suit == card.suit) {
      isDrawn = true;
    }
  }
  if (!isDrawn) {
    drawn_.push_back(card);
  }
  return isDrawn;
}
// I GOT A BIG OLE DICKY DICK BUT A TINY ASS PEANY WEENY BRAINY WAIN