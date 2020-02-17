#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#define HISTO_BAR_Scale 3

#include <vector>

class Histogram {
 public:
  Histogram();
  void DisplayValueHisto();
  void AddValue(int value);
  void SetHistoRange(int start_, int stop_);

 private:
  int start_{0};
  int stop_{0};
  std::vector<int> histogram_count_;
  std::vector<int> value_list_;

  void DisplayValueCounts();
  void DisplayHisto();
  double ScaleHistoValue(int value);
  void ResizeHistoVector();
};

#endif
