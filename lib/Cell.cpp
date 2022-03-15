#ifndef _CELLCPP_
#define _CELLCPP_

#include "Cell.hpp"
#include "Grid.hpp"

using namespace std;

Cell::Cell() { 
  StateDead *state;
  state_ = state;
}

Cell::Cell(State* state) { delete state_; state_ = state;  }

void Cell::updateState(){
  State* aux = state_->nextState();
  delete state_;
  state_ = aux;
  delete aux;
}

void Cell::setState(State* state){ delete state_; state_ = state; }

char Cell::getStateValue() const{ return state_->getState(); }
State* Cell::getState() const{ return state_; }

void Cell::setPosx(int value) { posx_ = value; }

void Cell::setPosY(int value) { posy_ = value; }

int Cell::getPosx() const { return posx_; }

int Cell::getPosY() const { return posy_; }

Cell::~Cell(){}

ostream& operator<<(ostream& os,const Cell& cl){ os << cl.getState(); return os; }

#endif