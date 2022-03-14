#ifndef _STATEEGGHPP_
#define _STATEEGGHPP_

#include "IState.hpp"

class StateEgg : public IState{

 public:
  IState* nextState(std::vector<IState&>);
  const char getState() const;

 private:
  int countStates(char, std::vector<IState&>);
  IState* findState(char, std::vector<IState&>);
};

#endif