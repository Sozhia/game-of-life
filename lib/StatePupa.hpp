#ifndef _STATEPUPAHPP_
#define _STATEPUPAHPP_

#include "IState.hpp"

class StateLarva : public IState{

 public:
  IState* nextState(std::vector<IState&>);
  char getState();

 private:
  int countStates(char, std::vector<IState&>);
  IState* findState(char, std::vector<IState&>);
};

#endif