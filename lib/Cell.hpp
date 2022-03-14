#ifndef _CELLHPP_
#define _CELLHPP_

#include "IState.hpp"

using namespace std;

class Grid;

class Cell{
 public:
   Cell();

   void updateState();
   std::vector<IState&> neighbors(const Grid&) const;

   void setPosx(int);
   void setPosY(int);
   int getPosx() const;
   int getPosY() const;

   IState* getState() const;
   ~Cell();

   friend ostream& operator<<(ostream&, const Cell&);

 private:
  int posx_, posy_;
  IState* state_;
};

#endif