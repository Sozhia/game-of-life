#ifndef _STATELARVACPP_
#define _STATELARVACPP_

#include "StateLarva.hpp"

void StateLarva::neighbors(const Grid& grid, int posx, int posy){
  int eggs_counter = 0;
  int larvas_counter = 0;
  int pupas_counter = 0;
  int adults_counter = 0;

  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'E')? eggs_counter++ : 0;
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'L')? larvas_counter++ : 0;
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'P')? pupas_counter++ : 0;
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'A')? adults_counter++ : 0;
      }
    }
  }
  setEggsAmount(eggs_counter);
  setLarvasAmount(larvas_counter);
  setPupasAmount(pupas_counter);
  setAdultsAmount(adults_counter);
}

State* StateLarva::nextState() {

 int sum_adult_pupa_egg = getAdultsAmount() + getPupasAmount() + getEggsAmount();

  if (getLarvasAmount() > sum_adult_pupa_egg){
    StateDead *state_dead;
    return state_dead;
  } else {
    StatePupa *state_pupa;
    return state_pupa;
  } 

}

int StateLarva::getLarvasAmount() const { return n_states_larva_; }
void StateLarva::setLarvasAmount(int value) { n_states_larva_ = value; }

int StateLarva::getEggsAmount() const { return n_states_egg_; }
void StateLarva::setEggsAmount(int value) {n_states_egg_ = value; }

int StateLarva::getPupasAmount() const { return n_states_pupa_; }
void StateLarva::setPupasAmount(int value) { n_states_pupa_ = value; }

int StateLarva::getAdultsAmount() const { return n_states_adult_; }
void StateLarva::setAdultsAmount(int value) { n_states_adult_ = value; }

const char StateLarva::getState() const {return 'L';}

#endif