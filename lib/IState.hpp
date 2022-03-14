#ifndef _STATEHPP_
#define _STATEHPP_

#include <vector>
#include <iostream>

class IState{
 public:
  virtual IState* nextState(std::vector<IState&>) = 0;
  virtual const char getState() const =0;

 private:
  virtual int countStates(char, std::vector<IState&>) = 0;
  virtual IState* findState(char, std::vector<IState&>) = 0;
};

#endif