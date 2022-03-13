#ifndef _STATEEGGHPP_
#define _STATEEGGHPP_

#include "IState.hpp"

class StateEgg : public IState{

 public:
  IState* nextState(std::vector<IState>);
  char getState();
};

#endif