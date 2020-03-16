#ifndef HISTOGRAM_H
#define HISTOGRAM_H

constexpr auto kHistoMaxSize = 60.0;
constexpr auto kHistoScale = 120.0;

#include <vector>

enum class Mode { Dice, Coin };

class Histogram {
 public:
  void DisplayStats(const Mode mode, std::vector<int> list);

 private:
  int start_{0};
  int stop_{0};
  std::vector<int> frequency_count_;

  void DisplayFreq(const Mode mode) const;
  void DisplayHisto(const Mode mode) const;
  void DisplayDataGroup(const Mode mode, const int loop) const;
  void PrintDiceSide(const int i) const;
  void PrintHeadsTails(const int i) const;
  void SetFreqList(std::vector<int> list);
  void SetHistoRange(const int start, const int stop);
  double ScaleHistoValue(const int value) const;
  void ResizeHistoVector();
};

#endif
