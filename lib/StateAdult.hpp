#ifndef _STATEADULTHPP_
#define _STATEADULTHPP_

#include "IState.hpp"

class StateAdult : public IState{

 public:
  IState* nextState(std::vector<IState&>);
  const char getState() const;

 private:
  int countStates(char, std::vector<IState&>);
  IState* findState(char, std::vector<IState&>);
};

#endif