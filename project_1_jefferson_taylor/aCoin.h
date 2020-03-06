#ifndef ACOIN_H
#define ACOIN_H

#include <string>
#include <vector>

constexpr auto kCoinSides = 2;

enum class Side { Heads, Tails };

class aCoin {
 public:
  operator std::string();
  std::string Toss();

  std::vector<int> toss_log_;
};

#endif
