#include "Histogram.h"
#include <algorithm>

Histogram::Histogram(int start, int stop, int step)
	: start(start), stop(stop), step(step)
{
	resizeHistoVector();
}

// prints out histogram to console
void Histogram::displayHisto() {
	int x_size = static_cast<int>(scaleHistoValues());
}

// adds a single value to the histogram object vector
void Histogram::addValue(int value) {
	histogram_count[value]++;
}

// changes the range of values that the histogram will store and
// initializes all values to zero
void Histogram::setHistoRange(int start, int stop, int step) {
	this->start = start;
	this->stop = stop;
	this->step = step;

	std::fill(histogram_count.begin(), histogram_count.end(), 0);
}

// finds the scaling factor for histogram data
double Histogram::scaleHistoValues() {
	int total_count, min = histogram_count[0], max = 0;

	for (int value_count : histogram_count) {
		total_count += value_count;

		if (value_count > max) {
			max = value_count;
		}
		if (value_count < min) {
			min = value_count;
		}
	}

	auto minmax = std::minmax_element(histogram_count.begin(), histogram_count.end());

	return (59.0 * (total_count - min) / (max - min)) + 1;
}

// sizes histogram vector to the amount of different values
void Histogram::resizeHistoVector() {
	int size = stop - start + 1;
	histogram_count.resize(size, 0);
}

unsigned int Histogram::getHistoSize() {
	return histogram_count.size();
}
