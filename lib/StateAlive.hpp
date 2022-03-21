#ifndef _STATEALIVEHPP_
#define _STATEALIVEHPP_

#include "State.hpp"
#include "Grid.hpp"

class StateAlive : public State {

 public:
  StateAlive();
  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;
  ~StateAlive();

 private:
  int n_states_alive_;
};

#endif