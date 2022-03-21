#ifndef _STATEHPP_
#define _STATEHPP_

class Grid;

class State {
 public:
  virtual void neighbors(const Grid&, int, int) = 0;
  virtual State* nextState() = 0;
  virtual const char getState() const = 0;
};

#endif