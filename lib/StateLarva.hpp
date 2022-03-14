#ifndef _STATELARVAHPP_
#define _STATELARVAHPP_

#include "IState.hpp"

class StateLarva : public IState{

 public:
  IState* nextState(std::vector<IState&>);
  const char getState() const;

 private:
  int countStates(char, std::vector<IState&>);
  IState* findState(char, std::vector<IState&>);
};

#endif