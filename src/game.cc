#include "game.hh"
#include "data.hh"
#include <random>
#include <time.h>

NBBgame::NBBgame(void) : turn(0) {
  seed = time(0);
  srand(seed);
  goal[0] = rand() % 9 + 1;
  goal[1] = rand() % 9 + 1;
  goal[2] = rand() % 9 + 1;
}

NBBgame::NBBgame(int seed) : turn(0), seed(seed) {
  srand(seed);
  goal[0] = rand() % 9 + 1;
  do {
    goal[1] = rand() % 9 + 1;
  } while (goal[0] == goal[1]);
  do {
    goal[2] = rand() % 9 + 1;
  } while (goal[0] == goal[2] || goal[1] == goal[2]);
}

void NBBgame::setseed(int seed) {
  this->seed = seed;
  srand(seed);
}

void NBBgame::newgame(void) {
  turn = 0;
  goal[0] = rand() % 9 + 1;
  do {
    goal[1] = rand() % 9 + 1;
  } while (goal[0] == goal[1]);
  do {
    goal[2] = rand() % 9 + 1;
  } while (goal[0] == goal[2] || goal[1] == goal[2]);
}

BSdata NBBgame::swing(int num) {
  BSdata res = {0, 0, 0};
  int sw[3] = {num / 100, num / 10 % 10, num % 10};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (goal[i] == sw[j])
        i == j ? res.strike++ : res.ball++;
    }
  }
  res.turn = ++turn;
  res.gameend = res.strike == 3;
  return res;
}