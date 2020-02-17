#include <stdlib.h>

#include <iostream>

#include "Dice.h"
#include "GameStats.h"
#include "Histogram.h"

int main() {
  int user_seed, rolls;
  Dice dice1, dice2;
  Histogram histo1, histo2, histo3;
  GameStats stats;

  std::cout << "Enter a seed value for the dice rolls: " << std::endl;
  std::cin >> user_seed;
  std::cout << "Enter amount of rolls: " << std::endl;
  std::cin >> rolls;
  srand(user_seed);
  std::cout << std::endl;

  std::cout << "Roll stats from first die:" << std::endl;
  stats.DisplayDiceStats(1, rolls, dice1, histo1);
  std::cout << "Roll stats from second die:" << std::endl;
  stats.DisplayDiceStats(1, rolls, dice2, histo2);
  std::cout << "Roll stats from first and second die Combined:" << std::endl;
  stats.CombineDiceRolls(dice2, dice1, histo3);
}
