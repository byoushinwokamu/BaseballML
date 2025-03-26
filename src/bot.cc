#include "bot.hh"

int NBBbot::makeSwing(void) {
  return n++;
  ;
}

void NBBbot::applyResult(BSdata dat) {
  if (dat.gameend)
    n = 123;
}
