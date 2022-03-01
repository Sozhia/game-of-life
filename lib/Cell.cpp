#ifndef _CELLCPP_
#define _CELLCPP_
#include "Cell.hpp"
#include "Grid.hpp"

using namespace std;

Cell::Cell() {}

Cell::Cell(int posx, int posy) {
  posx_ = posx;
  posy_ = posy;
}

State Cell::getState() const { return state_; }

State Cell::setState(State state) { state_ = state; }

void Cell::updateState() {
  if (state_== 0)  {
    (neighbors_ == 3)? state_ = 1 : state_ = 0 ;
  } else {
    (2 <= neighbors_ <= 3)? state_ = 1 : state_ = 0 ;
  }

}

int Cell::neighbors(const Grid& grid) {
  neighbors_ = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      grid.getCell(i,j).getState() == 1? neighbors_++ : 0;
    }
  }
}

ostream& Cell::operator<<(ostream& os, const Cell& cl){
  (cl.getState() == 0)? os <<  ' ': os << 'X';
  return os;
}

#endif