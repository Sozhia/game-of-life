#ifndef _STATEADULTCPP_
#define _STATEADULTCPP_

#include "StateAdult.hpp"

void StateAdult::neighbors(const Grid& grid, int posx, int posy){
  int counter = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'A')? counter++ : 0;
      }
    }
  }
  setAdultsAmount(counter);
}

State* StateAdult::nextState(){
  if (getAdultsAmount() > 0){
    StateEgg *state_egg;
    return state_egg;
  } else {
    StateDead *state_dead;
    return state_dead;
  }
}

int StateAdult::getAdultsAmount() const{ return n_states_adult_; }
void StateAdult::setAdultsAmount(int value) { n_states_adult_ = value; }

const char StateAdult::getState() const {return 'A';}

#endif