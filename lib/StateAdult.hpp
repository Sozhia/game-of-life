#ifndef _STATEADULTHPP_
#define _STATEADULTHPP_

#include "State.hpp"
#include "StateDead.hpp"

class StateAdult : public State{

 public:
  StateAdult(){}
  ~StateAdult(){}
  
  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;

  int getAdultsAmount() const;
  void setAdultsAmount(int);
 private:
  int n_states_adult_;
};

#endif