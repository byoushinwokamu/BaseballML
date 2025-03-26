#include <iostream>
#include <time.h>

#include "game.hh"

using namespace std;

int main() {
  NBBgame game(time(0));
  int n = 1;
  BSdata dat;

  while (n) {
    cout << "Swing: ";
    cin >> n;
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
