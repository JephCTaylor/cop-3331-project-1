#include "Histogram.h"

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>

Histogram::Histogram() {}

// prints the values counts and histogram
void Histogram::DisplayValueHisto() {
  DisplayValueCounts();
  DisplayHisto();
}

// prints out the counts of all values stored in the histogram
// example:
// 1: 2
// 2: 3
// 3: 1
void Histogram::DisplayValueCounts() {
  for (int i = 0; i < (stop_ - start_ + 1); i++) {
    std::cout << (i + start_) << ":\t" << histogram_count_[i] << std::endl;
  }
  std::cout << std::endl;
}

// prints out histogram to console
// example:
// 1: XX
// 2: XXX
// 3: X
void Histogram::DisplayHisto() {
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
