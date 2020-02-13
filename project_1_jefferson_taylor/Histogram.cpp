#include <stdlib.h>
#include <iostream>
#include "Histogram.h"

Histogram::Histogram() {}

Histogram::Histogram(int start, int stop, int step)
	: start(start), stop(stop), step(step)
{
	resizeHistoVector();
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

// adds a single value to the histogram object vector
void Histogram::addValue(int value) {
	histogram_count[value - start]++;
}

// changes the range of values that the histogram will store and
// initializes all values to zero
void Histogram::setHistoRange(int start, int stop, int step) {
	this->start = start;
	this->stop = stop;
	this->step = step;

	resizeHistoVector();
	std::fill(histogram_count.begin(), histogram_count.end(), 0);
}

// finds the scaling factor for histogram value
double Histogram::scaleHistoValue(int value) {
	int total_count = 0, min = histogram_count[0], max = 0;

	for (int value_count : histogram_count) {
		total_count += value_count;

		if (value_count > max) {
			max = value_count;
		}
		if (value_count < min) {
			min = value_count;
		}
	}

	return (59.0 / total_count * (value - total_count)) + 59;
}

// sizes histogram vector to the amount of different values
void Histogram::resizeHistoVector() {
	int size = stop - start + 1;
	histogram_count.resize(size, 0);
}

unsigned int Histogram::getHistoSize() {
	return histogram_count.size();
}
