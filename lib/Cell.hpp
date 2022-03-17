#ifndef _CELLHPP_
#define _CELLHPP_

#include "State.hpp"
#include "Grid.hpp"

using namespace std;

class Grid;
class State;

class Cell{
 public:
   Cell();

   void updateState();

   void setState(State*);
   char getStateValue() const;
   State* getState() const;

   void setPosx(int);
   void setPosY(int);
   int getPosx() const;
   int getPosY() const;

   ~Cell();

   friend ostream& operator<<(ostream&, const Cell&);

 private:
  int posx_, posy_;
  State* state_;
  
};

#endif