#ifndef _CELLCPP_
#define _CELLCPP_

#include "Cell.hpp"
#include "StateDead.hpp"

using namespace std;

Cell::Cell() { state_ = new StateDead; }

void Cell::updateState(){ state_ = getState()->nextState(); }

char Cell::getStateValue() const{ return state_->getState(); }
void Cell::setState(State* state){ state_ = state; }
State* Cell::getState() const{ return state_; }

void Cell::setPosx(int value) { posx_ = value; }
void Cell::setPosY(int value) { posy_ = value; }

int Cell::getPosx() const { return posx_; }
int Cell::getPosY() const { return posy_; }

Cell::~Cell(){}

ostream& operator<<(ostream& os,const Cell& cl){ os << cl.getState(); return os; }

#endif