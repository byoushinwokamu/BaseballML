#ifndef __GAME_HH__
#define __GAME_HH__

#include "data.hh"

class NBBgame {
private:
  int turn;
  int seed;
  int goal[3];

public:
  NBBgame(void);
  NBBgame(int seed);
  void setseed(int seed);
  void newgame(void);
  BSdata swing(int num);
};

#endif