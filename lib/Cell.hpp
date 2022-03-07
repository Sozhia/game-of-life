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
   void updateState();
   void neighbors(const Grid&);
   friend ostream& operator<<(ostream&, const Cell&);
   ~Cell();

 private:
  int posx_, posy_, neighbors_;
  State state_;
};

#endif