#ifndef _ISTATEHPP_
#define _ISTATEHPP_

#include <vector>
#include <iostream>
#include "Grid.hpp"
#include "Cell.hpp"

class State{
 public:
  virtual void neighbors(const Grid&, int, int) = 0;
  virtual State* nextState() = 0;
  virtual const char getState() const = 0;
};

#endif