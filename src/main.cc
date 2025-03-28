#include <iostream>
#include <time.h>

#include "bot.hh"
#include "game.hh"

using namespace std;

int main(int argc, char **argv) {
  NBBgame game(time(0));
  BSdata dat;
  NBBbot bot;
  int it;
  long long totalTurns = 0;
  cout << "How many games? ";
  cin >> it;

  for (int i = 0; i < it; i++) {
    while (true) {
      int n;
      n = bot.makeSwing();
      dat = game.swing(n);
      bot.applyResult(dat);

      if (dat.gameend) {
        // cout << " YOU WON IN " << dat.turn << " SWINGS, GOAL WAS " << n <<
        // endl;
        totalTurns += dat.turn;
        break;
      }
    }
    game.newgame();
  }

  cout << " Played " << it << " game(s)\n";
  cout << " Average: " << ((double)totalTurns / it) << " turns\n";

  return 0;
}
