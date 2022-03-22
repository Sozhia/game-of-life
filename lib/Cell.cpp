#ifndef _CELLCPP_
#define _CELLCPP_

#include "Cell.hpp"
#include "StateDead.hpp"

Cell::Cell(){state_ = new StateDead();}

Cell::Cell(int posx, int posy) { 
  state_ = new StateDead();
  posx_ = posx;
  posy_ = posy;
}

void Cell::updateState(){ state_ = getState()->nextState(); }

char Cell::getStateValue() const{ return state_->getState(); }
State* Cell::getState() const{ return state_; }
void Cell::setState(State* state) { state_= state; }

int Cell::getPosx() const { return posx_; }
int Cell::getPosY() const { return posy_; }

Cell::~Cell(){}

ostream& operator<<(ostream& os,const Cell& cl){ os << cl.getState(); return os; }

#endif