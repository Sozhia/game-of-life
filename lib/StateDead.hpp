#ifndef _STATEDEADHPP_
#define _STATEDEADHPP_

#include "IState.hpp"

class StateDead : public IState{

 public:
  IState* nextState(std::vector<IState&>);
  const char getState() const;

 private:
  int countStates(char, std::vector<IState&>);
  IState* findState(char, std::vector<IState&>);
};

#endif