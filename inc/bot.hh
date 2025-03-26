#ifndef __BOT_HH__
#define __BOT_HH__

#include "data.hh"

class NBBbot {
private:
  int n;

public:
  NBBbot();
  int makeSwing(void);
  void applyResult(BSdata dat);
};

#endif