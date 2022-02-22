#ifndef _CELLHPP_
#define _CELLHPP_

#include <iostream>

using namespace std;

class Grid;

class Cell{
 public:
   State getState() const;
   State setState(State);
   void updateState();
   int neighbors(const Grid&);
   ostream& operator<<(ostream&, const Cell&);

 private:
};

#endif