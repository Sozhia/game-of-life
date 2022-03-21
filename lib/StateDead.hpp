#ifndef _STATEDEADHPP_
#define _STATEDEADHPP_

#include "State.hpp"
#include "Grid.hpp"

class StateDead : public State {

 public:
  StateDead();
  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;
  ~StateDead();
 private:
  int n_states_alive_;
};

#endif