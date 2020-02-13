#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#define HISTO_BAR_SCALE 6

#include <vector>

class Histogram
{
public:
	Histogram();
	void displayHisto();
	void addValue(int value);
	void setHistoRange(int start, int stop, int step);

private:
	int start{ 0 };
	int stop{ 0 };
	int step{ 1 };
	std::vector<int> histogram_count;

	double scaleHistoValue(int value);
	void resizeHistoVector();
};

#endif
