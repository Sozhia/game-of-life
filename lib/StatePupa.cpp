#ifndef _STATEPUPACPP_
#define _STATEPUPACPP_

#include "StatePupa.hpp"
#include "StateDead.hpp"
#include "StateAdult.hpp"

void StatePupa::neighbors(const Grid& grid, int posx, int posy){
  n_states_egg_= 0;
  n_states_larva_ = 0;
  n_states_pupa_ = 0;
  n_states_adult_ = 0;
  n_states_dead_ = 0;

  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        (grid.getCell(posx + i, posy + j).getStateValue() == 'E')? n_states_egg_++ : 0;
        (grid.getCell(posx + i, posy + j).getStateValue() == 'L')? n_states_larva_++ : 0;
        (grid.getCell(posx + i, posy + j).getStateValue() == 'P')? n_states_pupa_++ : 0;
        (grid.getCell(posx + i, posy + j).getStateValue() == 'A')? n_states_adult_++ : 0;
        (grid.getCell(posx + i, posy + j).getStateValue() == 'D')? n_states_dead_++ : 0;
      }
    }
  }
}

State* StatePupa::nextState() {
  int sum_all = n_states_adult_ + n_states_pupa_ + n_states_egg_ + n_states_dead_;
  State* state;
  return (n_states_larva_ > sum_all)? state = new StateDead : state = new StateAdult;
}

const char StatePupa::getState() const {return 'P';}

#endif