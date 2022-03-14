#ifndef _CELLCPP_
#define _CELLCPP_

#include "Cell.hpp"
#include "Grid.hpp"

using namespace std;

Cell::Cell(IState* state) { delete state_; state_ = state;  }

void Cell::updateState(const Grid& grid) {
  getState()->nextState(neighbors(grid));
}

std::vector<IState&> Cell::neighbors(const Grid& grid) const{ 
  std::vector<IState&> states_collection;
  int counter = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        states_collection.push_back(grid.getCell(posx_ + i, posy_ + j).getState());
      }
    }
  }

  return states_collection;
}

void Cell::setPosx(int value) { posx_ = value; }
void Cell::setPosY(int value) { posy_ = value; }
int Cell::getPosx() const { return posx_; }
int Cell::getPosY() const { return posy_; }
IState* Cell::getState() const { return state_; }

Cell::~Cell(){}

ostream& operator<<(ostream& os,const Cell& cl){
  os << cl.getState()->getState();
  return os;
}

#endif