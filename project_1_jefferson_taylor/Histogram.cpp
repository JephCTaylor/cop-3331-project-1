#include "Histogram.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>

#include "aCoin.h"

// prints the frequency counts and histogram. Changes depending on mode
void Histogram::DisplayStats(const Mode mode, std::vector<int> list) {
  if (mode == Mode::Coin) {
    // if theres a coin flip and only tails itll make start_ = 1 and display all
    // flips as heads
    SetHistoRange(0, 1);
  } else {
    SetHistoRange(*std::min_element(list.begin(), list.end()),
                  *std::max_element(list.begin(), list.end()));
  }
  SetFreqList(list);
  DisplayFreq(mode);
  DisplayHisto(mode);
}

// prints out the counts of all values stored in the histogram
// example:
// 1: 2
// 2: 3
// 3: 1
void Histogram::DisplayFreq(const Mode mode) const {
  for (int i = 0; i < (stop_ - start_ + 1); i++) {
    if (!frequency_count_[i]) continue;
    DisplayDataGroup(mode, i);
    std::cout << frequency_count_[i] << std::endl;
  }
  std::cout << std::endl;
}

// prints out histogram to console
// example:
// 1: XX
// 2: XXX
// 3: X
void Histogram::DisplayHisto(const Mode mode) const {
  for (int i = 0; i < (stop_ - start_ + 1); i++) {
    if (!frequency_count_[i]) continue;
    DisplayDataGroup(mode, i);
    for (int j = 0; j < (ScaleHistoValue(frequency_count_[i])); j++) {
      if (j > kHistoMaxSize) continue;
      std::cout << "X";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// prints out different data depending on the game mode argument
void Histogram::DisplayDataGroup(const Mode mode, const int loop) const {
  switch (mode) {
    case Mode::Dice: {
      PrintDiceSide(loop);
      break;
    }
    case Mode::Coin: {
      PrintHeadsTails(loop);
      break;
    }
    default:
      std::cerr << "No mode was selected for Histogram::PrintStats()";
      break;
  }
}

void Histogram::PrintDiceSide(const int i) const {
  std::cout << (i + start_) << ":\t";
}

void Histogram::PrintHeadsTails(const int i) const {
  switch (i) {
    case static_cast<int>(Side::Heads):
      std::cout << "Heads:\t";
      break;
    case static_cast<int>(Side::Tails):
      std::cout << "Tails:\t";
      break;
  }
}

// sets the value list of the histogram class
void Histogram::SetFreqList(std::vector<int> list) {
  for (int value : list) {
    frequency_count_.at(value - start_)++;
  }
}

// changes the range of values that the histogram will store and
// initializes all values to zero
void Histogram::SetHistoRange(const int start, const int stop) {
  start_ = start;
  stop_ = stop;

  ResizeHistoVector();
  std::fill(frequency_count_.begin(), frequency_count_.end(), 0);
}

// finds the scaling factor for each histogram value
double Histogram::ScaleHistoValue(const int value) const {
  int total_count =
      std::accumulate(frequency_count_.begin(), frequency_count_.end(), 0);
  return (kHistoScale / total_count * (value - total_count)) + kHistoScale;
}

// sizes histogram vector to the amount of different values
void Histogram::ResizeHistoVector() {
  frequency_count_.resize(stop_ - start_ + 1, 0);
}
