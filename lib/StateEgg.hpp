#ifndef _STATEEGGHPP_
#define _STATEEGGHPP_

#include "State.hpp"
#include "StateDead.hpp"
#include "StateAdult.hpp"
#include "StateLarva.hpp"

class StateEgg : public State{

 public:
  StateEgg(){}
  ~StateEgg(){}
  
  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;

  int getLarvasAmount() const;
  void setLarvasAmount(int);

  int getEggsAmount() const;
  void setEggsAmount(int);

 private:
  int n_states_larva_;
  int n_states_egg_;

};

#endif