#ifndef _CELLHPP_
#define _CELLHPP_

#include "State.hpp"
#include "Grid.hpp"
#include <iostream>

using namespace std;

class Grid;
class State;

class Cell{
 public:
   Cell();
   Cell(int, int);

   void updateState();

   char getStateValue() const;
   State* getState() const;
   void setState(State*);

   int getPosx() const;
   int getPosY() const;

   ~Cell();

   friend ostream& operator<<(ostream&, const Cell&);

 private:
  int posx_, posy_;
  State* state_;
  
};

#endif