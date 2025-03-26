#ifndef __BOT_HH__
#define __BOT_HH__

#include "data.hh"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class NBBbot {
private:
  vector<int> last_guess;
  map<int, int> number_freq;

public:
  NBBbot();
  int weighted_random_pick(const vector<int> &exclude);
  int makeSwing(void);
  void applyResult(BSdata dat);
};

#endif