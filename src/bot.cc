#include "bot.hh"

NBBbot::NBBbot(void) : mlp(5, 5, 3) {
  prevSwing[0] = 0;
  prevSwing[1] = 0;
  prevSwing[2] = 0;
  prevDat = {0, 0, 0, 0};
}

int NBBbot::makeSwing(void) {
  if (prevDat.turn == 0) {
    prevSwing[0] = 1;
    prevSwing[1] = 2;
    prevSwing[2] = 3;
    return 123;
  }

  vector<double> input(5);
  for (int i = 0; i < 3; i++)
    input[i] = prevSwing[i];
  input[3] = prevDat.ball, input[4] = prevDat.strike;
  auto res = mlp.convert_output(mlp.forward(input));
  return res[0] * 100 + res[1] * 10 + res[2];
}

void NBBbot::applyResult(BSdata dat) {
  if (dat.gameend) {
    prevSwing[0] = 0;
    prevSwing[1] = 0;
    prevSwing[2] = 0;
    prevDat = {0, 0, 0, 0};
  } else {
    prevDat = dat;
  }
}
