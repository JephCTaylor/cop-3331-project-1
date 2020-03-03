#include "Histogram.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>

#include "aCoin.h"

Histogram::Histogram() {}

// prints the values counts and histogram
void Histogram::DisplayStats(Mode mode, std::vector<int> list, int lower,
                             int upper) {
  SetHistoRange(lower, upper);
  for (int x : list) {
    AddValue(x);
  }
  PrintStats(mode);
}

// prints out different data depending on the game mode argument
void Histogram::PrintStats(Mode mode) {
  switch (mode) {
    case Mode::Dice: {
      DisplayRollFreq();
      DisplayRollHisto();
      break;
    }
    case Mode::Coin: {
      DisplayTossFreq();
      DisplayTossHisto();
      break;
    }
    default:
      std::cerr << "No mode was selected for Histogram::PrintStats()";
      break;
  }
}

// prints out the counts of all values stored in the histogram
// example:
// 1: 2
// 2: 3
// 3: 1
void Histogram::DisplayRollFreq() {
  for (int i = 0; i < (stop_ - start_ + 1); i++) {
    std::cout << (i + start_) << ":\t" << histogram_count_[i] << std::endl;
  }
  std::cout << std::endl;
}

// display freq for coin toss
void Histogram::DisplayTossFreq() {
  for (int i = 0; i < COIN_SIDES; i++) {
    switch (i) {
      case Heads:
        std::cout << "Heads:\t" << histogram_count_[i] << std::endl;
        break;
      case Tails:
        std::cout << "Tails:\t" << histogram_count_[i] << std::endl;
        break;
    }
  }
  std::cout << std::endl;
}

// prints out histogram to console
// example:
// 1: XX
// 2: XXX
// 3: X
void Histogram::DisplayRollHisto() {
  for (int i = 0; i < (stop_ - start_ + 1); i++) {
    std::cout << (i + start_) << ":\t";
    for (int j = 0;
         j < (ScaleHistoValue(histogram_count_[i] * HISTO_BAR_SCALE)); j++) {
      std::cout << "X";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// display histo made for coin toss
void Histogram::DisplayTossHisto() {
  for (int i = 0; i < COIN_SIDES; i++) {
    switch (i) {
      case Heads:
        std::cout << "Heads:\t";
        break;
      case Tails:
        std::cout << "Tails:\t";
        break;
    }
    for (int j = 0;
         j < (ScaleHistoValue(histogram_count_[i] * HISTO_BAR_SCALE)); j++) {
      std::cout << "X";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// Adds a single value to the histogram object vector, and all values
// will be stored in the value_list_ for possible later use
void Histogram::AddValue(int value) {
  histogram_count_[value - start_]++;
  value_list_.push_back(value);
}

// changes the range of values that the histogram will store and
// initializes all values to zero
void Histogram::SetHistoRange(int start, int stop) {
  start_ = start;
  stop_ = stop;

  ResizeHistoVector();
  std::fill(histogram_count_.begin(), histogram_count_.end(), 0);
}

// finds the scaling factor for each histogram value
double Histogram::ScaleHistoValue(int value) {
  int total_count =
      std::accumulate(histogram_count_.begin(), histogram_count_.end(), 0);
  return (59.0 / total_count * (value - total_count)) + 59;
}

// sizes histogram vector to the amount of different values
void Histogram::ResizeHistoVector() {
  int size = stop_ - start_ + 1;
  histogram_count_.resize(size, 0);
}
