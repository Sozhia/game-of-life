#ifndef _STATEHPP_
#define _STATEHPP_

#include "Grid.hpp"

class State{
 public:
  virtual int neighbors(const Grid&, int, int)=0;
  virtual State* nextState()=0;
  virtual char getState() const =0;
};

#endif