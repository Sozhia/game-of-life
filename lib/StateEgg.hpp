#ifndef _STATEEGGHPP_
#define _STATEEGGHPP_

#include <iostream>
#include "IState.hpp"

class StateEgg : public State{
 public:
  StateEgg();
  int neighbors(const Grid&, int, int);
  State* nextState();
  char getState() const;
  friend ostream& operator<<(ostream&, const State&);
};

#endif