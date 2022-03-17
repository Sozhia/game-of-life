#ifndef _STATEEGGHPP_
#define _STATEEGGHPP_

#include "State.hpp"
#include "Grid.hpp"

class StateEgg : public State{

 public:
  
  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;

 private:
  int n_states_larva_;
  int n_states_egg_;

};

#endif