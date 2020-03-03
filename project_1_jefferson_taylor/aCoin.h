#ifndef ACOIN_H
#define ACOIN_H

#include <string>
#include <vector>

#define COIN_SIDES 2

enum Side { Heads, Tails };

class aCoin {
 public:
  std::string Toss();
  operator std::string();

  std::vector<int> toss_log_;
};

#endif
