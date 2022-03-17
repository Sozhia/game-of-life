#ifndef _STATEDEADCPP_
#define _STATEDEADCPP_

#include "StateDead.hpp"
#include "StateEgg.hpp"
#include "StateDead.hpp"

void StateDead::neighbors(const Grid& grid, int posx, int posy){
  n_states_adult_ = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        (grid.getCell(posx + i, posy + j).getStateValue() == 'A')? n_states_adult_++ : 0;
      }
    }
  }
}

State* StateDead::nextState() {
  State* state;
  return (n_states_adult_ >= 2)?state = new StateEgg : state = new StateDead ;
}

const char StateDead::getState() const {return 'D';}

#endif