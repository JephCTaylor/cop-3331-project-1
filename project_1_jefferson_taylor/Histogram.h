#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#define HISTO_BAR_SCALE 3

#include <vector>

enum class Mode { Dice, Coin };

class Histogram {
 public:
  void DisplayStats(const Mode mode, std::vector<int> list, const int lower,
                    const int upper);
  void AddValue(const int value);
  void SetHistoRange(const int start, const int stop);

 private:
  int start_{0};
  int stop_{0};
  std::vector<int> histogram_count_;
  std::vector<int> value_list_;

  void DisplayFreq(const Mode mode) const;
  void DisplayHisto(const Mode mode) const;
  void DisplayDataGroup(const Mode mode, const int loop) const;
  void PrintHeadsTails(const int i) const;
  void PrintDiceSide(const int i) const;
  double ScaleHistoValue(const int value) const;
  void ResizeHistoVector();
};

#endif
