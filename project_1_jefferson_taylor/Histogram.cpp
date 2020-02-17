#include <stdlib.h>
#include <iostream>
#include <numeric>
#include <algorithm>
#include "Histogram.h"

Histogram::Histogram() {}

// prints the values counts and histogram 
void Histogram::displayValueHisto() {
	displayValueCounts();
	displayHisto();
}

//prints out the counts of all values stored in the histogram 
void Histogram::displayValueCounts() {
	for (int i = 0; i < (stop - start + 1); i++) {
		std::cout << (i + start) << ":\t" << histogram_count[i] << std::endl;
	}
	std::cout << std::endl;
}

// prints out histogram to console
void Histogram::displayHisto() {
	for (int i = 0; i < (stop - start + 1); i++) {
		std::cout << (i + start) << ":\t";
		for (int j = 0; j < (scaleHistoValue(histogram_count[i] * HISTO_BAR_SCALE)); j++) {
			std::cout << "X";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// adds a single value to the histogram object vector, and all values
// will be stored in the value_list for possible later use
void Histogram::addValue(int value) {
	histogram_count[value - start]++;
	value_list.push_back(value);
}

// changes the range of values that the histogram will store and
// initializes all values to zero
void Histogram::setHistoRange(int start, int stop) {
	this->start = start;
	this->stop = stop;

	resizeHistoVector();
	std::fill(histogram_count.begin(), histogram_count.end(), 0);
}

// finds the scaling factor for each histogram value
double Histogram::scaleHistoValue(int value) {
	int total_count = std::accumulate(histogram_count.begin(), histogram_count.end(), 0);
	return (59.0 / total_count * (value - total_count)) + 59;
}

// sizes histogram vector to the amount of different values
void Histogram::resizeHistoVector() {
	int size = stop - start + 1;
	histogram_count.resize(size, 0);
}
