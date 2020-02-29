#include <stdlib.h>

#include <iostream>

#include "Dealer.h"
#include "aDie.h"
#include "GameStats.h"
#include "Histogram.h"

int main() {
  int user_seed, rolls;
  aDie dice1, dice2;
  Histogram histo;
  GameStats stats;
  Dealer dealer;

  std::cout << "Enter a seed value for the aDie rolls: " << std::endl;
  std::cin >> user_seed;
  std::cout << "Enter amount of rolls: " << std::endl;
  std::cin >> rolls;
  srand(user_seed);
  std::cout << std::endl;

  dealer.AddDie(&dice1);
  std::cout << "Roll stats from first die:" << std::endl;
  stats.DisplayRollStats(rolls, dealer, histo);
  dealer.ClearDice();
  dealer.ClearLogs();

  dealer.AddDie(&dice2);
  std::cout << "Roll stats from second die:" << std::endl;
  stats.DisplayRollStats(rolls, dealer, histo);
  dealer.ClearDice();
  dealer.ClearLogs();

  std::cout << "Roll stats from first and second die summed:" << std::endl;
  stats.SumDiceRolls(dice2, dice1, histo);

  std::cout << "Roll stats from first and second die multipled:" << std::endl;
  stats.MultiplyDiceRolls(dice1, dice2, histo);
}
