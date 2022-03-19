#ifndef _STATEALIVECPP_
#define _STATEALIVECPP_

#include "StateAlive.hpp"
#include "StateDead.hpp"

void StateAlive::neighbors(const Grid& grid, int posx, int posy){
  n_states_alive_ = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        (grid.getCell(posx + i, posy + j).getStateValue() == 'X')? n_states_alive_++ : 0;
      }
    }
  }
}

State* StateAlive::nextState(){
  State* state;
  return (2 <= n_states_alive_ <= 3)? state = new StateAlive: state = new StateDead ;
}

const char StateAlive::getState() const {return 'X';}

#endif