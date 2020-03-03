#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#define HISTO_BAR_SCALE 3

#include <vector>

enum class Mode { Dice, Coin };

class Histogram {
 public:
  void DisplayStats(Mode mode, std::vector<int> list, int lower, int upper);
  void DisplayDataGroup(Mode mode, int loop);
  void AddValue(int value);
  void SetHistoRange(int start, int stop);

 private:
  int start_{0};
  int stop_{0};
  std::vector<int> histogram_count_;
  std::vector<int> value_list_;

  void DisplayFreq(Mode mode);
  void DisplayHisto(Mode mode);
  void PrintHeadsTails(int i);
  void PrintDiceSide(int i);
  double ScaleHistoValue(int value);
  void ResizeHistoVector();
};

#endif
