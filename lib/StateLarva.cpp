#ifndef _STATELARVACPP_
#define _STATELARVACPP_

#include "StateLarva.hpp"
#include "StateDead.hpp"
#include "StatePupa.hpp"

void StateLarva::neighbors(const Grid& grid, int posx, int posy){
  n_states_egg_ = 0;
  n_states_larva_ = 0;
  n_states_pupa_ = 0;
  n_states_adult_ = 0;

  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        (grid.getCell(posx + i, posy + j).getStateValue() == 'E')? n_states_egg_++ : 0;
        (grid.getCell(posx + i, posy + j).getStateValue() == 'L')? n_states_larva_++ : 0;
        (grid.getCell(posx + i, posy + j).getStateValue()== 'P')? n_states_pupa_++ : 0;
        (grid.getCell(posx + i, posy + j).getStateValue() == 'A')? n_states_adult_++ : 0;
      }
    }
  }
}

State* StateLarva::nextState() {
  int sum_adult_pupa_egg = n_states_adult_ + n_states_pupa_ + n_states_egg_;
  State* state;
  return (n_states_larva_ > sum_adult_pupa_egg)? state = new StateDead : state = new StatePupa ;
}

const char StateLarva::getState() const {return 'L';}

#endif