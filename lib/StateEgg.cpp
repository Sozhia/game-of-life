#ifndef _STATEEGGCPP_
#define _STATEEGGCPP_

#include "StateEgg.hpp"

void StateEgg::neighbors(const Grid& grid, int posx, int posy){
  int eggs_counter = 0;
  int larvas_counter = 0;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'E')? eggs_counter++ : 0;
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'L')? larvas_counter++ : 0;
      }
    }
  }
  setEggsAmount(eggs_counter);
  setLarvasAmount(larvas_counter);
}

State* StateEgg::nextState() {
  if (getLarvasAmount() > getEggsAmount()){
    StateDead *state_dead;
    return state_dead;
  } else {
    StateLarva *state_larva;
    return state_larva;
  }
}

const char StateEgg::getState() const {return 'E';}

int StateEgg::getLarvasAmount() const {return n_states_larva_;}
void StateEgg::setLarvasAmount(int value) { n_states_larva_ = value; }

int StateEgg::getEggsAmount() const {return n_states_egg_;}
void StateEgg::setEggsAmount(int value) { n_states_egg_ = value; }

#endif