#ifndef _STATEDEADHPP_
#define _STATEDEADHPP_

#include "State.hpp"
#include "Grid.hpp"

class StateDead : public State {

 public:
   
  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;

 private:
  int n_states_adult_;
};

#endif