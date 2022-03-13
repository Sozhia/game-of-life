#ifndef _STATEPUPAHPP_
#define _STATEPUPAHPP_

#include "IState.hpp"

class StatePupa : public IState{

 public:
  IState* nextState(std::vector<IState>);
  char getState();
};

#endif