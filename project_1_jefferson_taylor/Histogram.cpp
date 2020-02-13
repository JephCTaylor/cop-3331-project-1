#include "Histogram.h"

Histogram::Histogram(int start, int stop, int step)
	: start(start), stop(stop), step(step)
{
	resizeHistoVector();
}

void Histogram::addValue(int value) {
	histogram_count[value]++;
}

void Histogram::setHistoRange(int start, int stop, int step) {
	this->start = start;
	this->stop = stop;
	this->step = step;

	std::fill(histogram_count.begin(), histogram_count.end(), 0);
}

void Histogram::resizeHistoVector() {
	int size = stop - start + 1;
	histogram_count.resize(size, 0);
}

int Histogram::getHistoSize() {
	return histogram_count.size();
}
