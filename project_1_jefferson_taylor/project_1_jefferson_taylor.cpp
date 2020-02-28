#include <stdlib.h>

#include <iostream>

#include "Dealer.h"
#include "Dice.h"
#include "GameStats.h"
#include "Histogram.h"

int main() {
  int user_seed, rolls;
  Dice dice1, dice2;
  Histogram histo;
  GameStats stats;
  Dealer dealer;

  std::cout << "Enter a seed value for the dice rolls: " << std::endl;
  std::cin >> user_seed;
  std::cout << "Enter amount of rolls: " << std::endl;
  std::cin >> rolls;
  srand(user_seed);
  std::cout << std::endl;

  dealer.AddDie(&dice1);
  std::cout << "Roll stats from first die:" << std::endl;
  stats.DisplayRollStats(rolls, dealer, histo);

  dealer.ClearDice();
  dealer.AddDie(&dice2);
  std::cout << "Roll stats from second die:" << std::endl;
  stats.DisplayRollStats(rolls, dealer, histo);

  std::cout << "Roll stats from first and second die Combined:" << std::endl;
  stats.CombineDiceRolls(dice2, dice1, histo);
}
