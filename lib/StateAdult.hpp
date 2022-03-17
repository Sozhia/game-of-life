#ifndef _STATEADULTHPP_
#define _STATEADULTHPP_

#include "State.hpp"
#include "Grid.hpp"

class StateAdult : public State {

 public:
  
  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;

 private:
  int n_states_adult_;
};

#endif