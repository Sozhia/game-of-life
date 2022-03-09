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
   void setState(State);
   void setPosx(int);
   void setPosY(int);
   void setAliveNeighbors(int);
   void updateState();
   int neighbors(const Grid&);
   int getNeighbors();
   friend ostream& operator<<(ostream&, const Cell&);
   ~Cell();

 private:
  int posx_, posy_, alive_neighbors_;
  State state_;
};

#endif