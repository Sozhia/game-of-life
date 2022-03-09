#ifndef _CELLCPP_
#define _CELLCPP_

#include "Cell.hpp"
#include "Grid.hpp"

using namespace std;

Cell::Cell() { setState(0); setAliveNeighbors(0);}

void Cell::updateState() {
  if (getState() == 0) {
    (getNeighbors() == 3) ? setState(1) : setState(0);
  } else {
    if (getNeighbors() == 2 || getNeighbors() == 3) {
      setState(1);
    } else { 
      setState(0);
    }
  }
}

int Cell::neighbors(const Grid& grid) { 
  int counter = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        if(grid.getCell(posx_ + i, posy_ + j).getState() == 1) {
          counter ++;
        } 
      }
    }
  }
  setAliveNeighbors(counter);
  return counter;
}

void Cell::setPosx(int value) { posx_ = value; }
void Cell::setPosY(int value) { posy_ = value; }
int Cell::getNeighbors() { return alive_neighbors_; }
void Cell::setAliveNeighbors(int value) { alive_neighbors_ = value; }
State Cell::getState() const { return state_; }
void Cell::setState(State state) { state_ = state; }

Cell::~Cell(){}

ostream& operator<<(ostream& os,const Cell& cl){
  (cl.getState() == 0)? os <<  " " : os << "X";
  return os;
}

#endif