#ifndef _STATEDEADHPP_
#define _STATEDEADHPP_

#include "State.hpp"
#include "StateEgg.hpp"
#include "StateAdult.hpp"

class StateDead : public State{

 public:
  StateDead(){}
  ~StateDead(){}
  
  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;

  int getAdultsAmount() const;
  void setAdultsAmount(int);

 private:
  int n_states_adult_;
};

#endif