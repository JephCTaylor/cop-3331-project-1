#ifndef ACARD_H
#define ACARD_H

#include <array>
#include <iostream>
#include <vector>

constexpr auto kBrands = 12;
constexpr auto kSuits = 4;

enum class Brand {
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Jack,
  Queen,
  King
};

enum class Suit { Spades, Hearts, Diamonds, Clubs };

struct aCard {
  void DisplayCard() const;

  Brand brand;
  Suit suit;

  const std::array<std::string, kBrands> brands{"A", "2", "3", "4", "5", "6",
                                                 "7", "8", "9", "J", "Q", "K"};
  const std::array<std::string, kSuits> suits{"S", "H", "D", "C"};
};

#endif  // !ACARD_H
