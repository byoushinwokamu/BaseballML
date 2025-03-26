#ifndef __BOT_HH__
#define __BOT_HH__

#include "data.hh"
#include "mlp.hh"

class NBBbot {
private:
  MLP mlp;
  int prevSwing[3];
  BSdata prevDat;

public:
  NBBbot();
  int makeSwing(void);
  void applyResult(BSdata dat);
};

#endif