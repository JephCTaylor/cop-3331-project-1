#include <stdlib.h>

#include <iostream>

#include "Dealer.h"
#include "GameStats.h"
#include "Histogram.h"
#include "aDie.h"

int main() {
  int user_seed, plays;
  aDie dice1, dice2;
  aCoin coin;
  Histogram histo;
  GameStats stats;
  Dealer dealer;

  std::cout << "Enter a seed value for the aDie rolls:" << std::endl;
  std::cin >> user_seed;
  std::cout << "Enter amount of times each game will be played:" << std::endl;
  std::cin >> plays;
  srand(user_seed);
  std::cout << std::endl;

  dealer.AddDie(&dice1);
  std::cout << "Roll stats from first die:" << std::endl;
  stats.DisplayRollStats(plays, dealer, histo);
  dealer.ClearDice();
  dealer.ClearLogs();

  dealer.AddDie(&dice2);
  std::cout << "Roll stats from second die:" << std::endl;
  stats.DisplayRollStats(plays, dealer, histo);
  dealer.ClearDice();
  dealer.ClearLogs();

  std::cout << "Roll stats from first and second die summed:" << std::endl;
  stats.SumDiceRolls(dice2, dice1, histo);

  std::cout << "Roll stats from first and second die multipled:" << std::endl;
  stats.MultiplyDiceRolls(dice1, dice2, histo);

  std::cout << "Coin toss stats displaying heads and tails:" << std::endl;
  stats.DisplayTossStats(plays, dealer, histo);
}
