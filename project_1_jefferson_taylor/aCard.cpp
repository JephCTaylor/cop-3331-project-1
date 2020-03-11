#include "aCard.h"

// prints out "BRAND-SUIT " of the card
void aCard::DisplayCard() const {
  std::cout << brands.at(static_cast<int>(brand)) << "-"
            << suits.at(static_cast<int>(suit)) << " ";
}
