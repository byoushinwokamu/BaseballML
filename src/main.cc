#include <iostream>
#include <time.h>

#include "bot.hh"
#include "game.hh"
#include "mlp.hh"

using namespace std;

int main() {
  // MLP mlp(3, 5, 3);
  // vector<double> input = {1, 2, 3};
  // vector<double> output = mlp.forward(input);
  // cout << "Output is ";
  // for (auto num : output)
  //   cout << num << ' ';
  // cout << endl;

  NBBgame game(time(0));
  BSdata dat;
  NBBbot bot;
  int it;
  long long totalTurns = 0;
  cout << "How many games? ";
  cin >> it;

  int a = 5;
  for (int i = 0; i < it; i++) {
    while (a--) {
      int n;
      n = bot.makeSwing();
      cout << "Trying " << n << endl;
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
