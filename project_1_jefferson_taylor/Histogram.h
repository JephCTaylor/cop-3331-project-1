#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>

class Histogram
{
public:
	Histogram(int start, int stop, int step);
	void displayHisto();
	void addValue(int value);
	void setHistoRange(int start, int stop, int step);
	unsigned int getHistoSize();

private:
	int start{ 0 };
	int stop{ 0 };
	int step{ 1 };
	std::vector<int> histogram_count;

	double scaleHistoValues();
	void resizeHistoVector();
};

#endif
