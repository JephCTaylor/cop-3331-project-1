#include <stdlib.h>

#include <iostream>

#include "GameStats.h"
#include "Histogram.h"
#include "aDeckOfCards.h"
#include "aDie.h"

int main() {
  int user_seed, plays;
  aDie dice1, dice2;
  aCoin coin;
  aDeckOfCards deck;
  Histogram histo;
  GameStats stats;

  std::cout << "Enter a seed value for the aDie rolls:" << std::endl;
  std::cin >> user_seed;
  std::cout << "Enter amount of times each game will be played:" << std::endl;
  std::cin >> plays;
  srand(user_seed);
  std::cout << std::endl;

  std::cout << "Roll stats from first die:" << std::endl;
  stats.DisplayRollStats(plays, dice1, histo);

  std::cout << "Roll stats from second die:" << std::endl;
  stats.DisplayRollStats(plays, dice2, histo);

  std::cout << "Roll stats from first and second die summed:" << std::endl;
  stats.CombineDiceRolls(dice2, dice1, histo, std::plus<int>());

  std::cout << "Roll stats from first and second die multipled:" << std::endl;
  stats.CombineDiceRolls(dice1, dice2, histo, std::multiplies<int>());

  std::cout << "Coin toss stats displaying heads and tails:" << std::endl;
  stats.DisplayTossStats(plays, coin, histo);

  std::cout << "Dealing hands and replacing cards:" << std::endl;
  stats.DealHands(deck, 4, 5, true);
  deck.ResetDeck();
  std::cout << "Dealing hands without replacing cards:" << std::endl;
  stats.DealHands(deck, 4, 5, false);
}
