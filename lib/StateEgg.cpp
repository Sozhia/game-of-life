#ifndef _STATEEGGCPP_
#define _STATEEGGCPP_

#include "StateEgg.hpp"
#include "StateDead.hpp"
#include "StateLarva.hpp"

void StateEgg::neighbors(const Grid& grid, int posx, int posy){
  n_states_egg_ = 0;
  int larvas_counter = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        (grid.getCell(posx + i, posy + j).getStateValue() == 'E')? n_states_egg_++ : 0;
        (grid.getCell(posx + i, posy + j).getStateValue() == 'L')? n_states_larva_++ : 0;
      }
    }
  }
}

State* StateEgg::nextState() {
  State* state;
  return (n_states_larva_ > n_states_egg_)? state = new StateDead : state = new StateLarva ;
}

const char StateEgg::getState() const {return 'E';}

#endif