#ifndef _CELLCPP_
#define _CELLCPP_

#include "Cell.hpp"
#include "Grid.hpp"

using namespace std;

Cell::Cell() { state_ = 0; }

State Cell::getState() const { return state_; }

void Cell::setState(State state) { state_ = state; }

void Cell::updateState() {
  if (getState() == 0) {
    if (neighbors_ == 3){ 
      setState(1);
    } else {
      setState(0);
    }
  } else {
    if ((neighbors_ >= 2)&&(neighbors_ <= 3)) {
      setState(1);
    } else { 
      setState(0);
    }
  }

}

void Cell::neighbors(const Grid& grid) { 
  neighbors_ = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (i != 0 && j != 0) {
        if(grid.getCell(posx_+(i),posy_+(j)).getState() == 1){
          neighbors_++;
        } 
      }
    }
  }
}

void Cell::setPosx(int value) { posx_ = value; }
void Cell::setPosY(int value) { posy_ = value; }

Cell::~Cell(){}

ostream& operator<<(ostream& os,const Cell& cl){
  (cl.getState() == 0)? os <<  " " : os << "X";
  return os;
}


#endif