#ifndef _STATEADULTHPP_
#define _STATEADULTHPP_

#include "IState.hpp"

class StateAdult : public IState{

 public:
  IState* nextState(std::vector<IState>);
  char getState();
};

#endif