#include <iostream>
#include <time.h>

#include "bot.hh"
#include "game.hh"

using namespace std;

int main() {
  NBBgame game(time(0));
  BSdata dat;
  NBBbot bot;
  int n = 1;

  while (n) {
    n = bot.makeswing();
    cout << "Swing: " << n << endl;
    dat = game.swing(n);
    if (dat.gameend) {
      cout << " YOU WON IN " << dat.turn << " SWINGS" << endl;
      break;
    } else {
      cout << " " << dat.ball << " Ball(s) " << dat.strike << " Strike(s)"
           << endl;
    }
  }

  return 0;
}
