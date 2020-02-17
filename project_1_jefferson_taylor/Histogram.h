#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#define HISTO_BAR_SCALE 3

#include <vector>

class Histogram
{
public:
	Histogram();
	void displayValueHisto();
	void addValue(int value);
	void setHistoRange(int start, int stop);

private:
	int start{ 0 };
	int stop{ 0 };
	std::vector<int> histogram_count;
	std::vector<int> value_list;

	void displayValueCounts();
	void displayHisto();
	double scaleHistoValue(int value);
	void resizeHistoVector();
};

#endif
