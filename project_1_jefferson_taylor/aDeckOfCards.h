#ifndef ADECKOFCARD_H
#define ADECKOFCARD_H

#include <array>
#include <iostream>
#include <vector>

constexpr auto kBrands = 12;
constexpr auto kSuits = 4;

enum class Brand : char {
  Ace = 'A',
  Two = '2',
  Three = '3',
  Four = '4',
  Five = '5',
  Six = '6',
  Seven = '7',
  Eight = '8',
  Nine = '9',
  Jack = 'J',
  Queen = 'Q',
  King = 'K'
};

enum class Suit : char {
  Spades = 'S',
  Hearts = 'H',
  Diamonds = 'D',
  Clubs = 'C'
};

struct Card {
  Brand brand;
  Suit suit;

  // prints out "BRAND-SUIT " of the card
  void DisplayCard() const {
    std::cout << static_cast<char>(brand) << "-" << static_cast<char>(suit)
              << " ";
  }
};

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
  std::array<Brand, kBrands> brands{Brand::Ace,   Brand::Two,   Brand::Three,
                                    Brand::Four,  Brand::Five,  Brand::Six,
                                    Brand::Seven, Brand::Eight, Brand::Nine,
                                    Brand::Jack,  Brand::Queen, Brand::King};
  std::array<Suit, kSuits> suits{Suit::Clubs, Suit::Diamonds, Suit::Hearts,
                                 Suit::Spades};
};

#endif  // !ADECKOFCARD_H
