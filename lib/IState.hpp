#ifndef _STATEHPP_
#define _STATEHPP_

#include <vector>
#include <iostream>

class IState{
 public:
  virtual IState* nextState(std::vector<IState>) = 0;
  virtual char getState() const =0;
};

#endif