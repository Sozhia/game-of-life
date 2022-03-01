#ifndef _CELLHPP_
#define _CELLHPP_

#include <iostream>

using namespace std;
typedef int State;

class Grid;

class Cell{
 public:
   Cell();
   State getState() const;
   State setState(State);
   void updateState();
   int neighbors(const Grid&);
   ostream& operator<<(ostream&, const Cell&);
   ~Cell();

 private:
  int posx_, posy_, neighbors_;
  State state_;
};

#endif