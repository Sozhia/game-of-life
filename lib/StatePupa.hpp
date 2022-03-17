#ifndef _STATEPUPAHPP_
#define _STATEPUPAHPP_

#include "State.hpp"
#include "Grid.hpp"

class StatePupa : public State{

 public:

  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;

 private:
  int n_states_larva_, n_states_pupa_, n_states_dead_, n_states_egg_, n_states_adult_;

};

#endif