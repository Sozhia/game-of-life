#ifndef _CELLHPP_
#define _CELLHPP_

#include "State.hpp"
#include "StateDead.hpp"

using namespace std;

class Grid;

class Cell{
 public:
   Cell();
   Cell(State*);

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