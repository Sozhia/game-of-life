#ifndef _STATEPUPACPP_
#define _STATEPUPACPP_

#include "StatePupa.hpp"

void StatePupa::neighbors(const Grid& grid, int posx, int posy){
  int eggs_counter = 0;
  int larvas_counter = 0;
  int pupas_counter = 0;
  int adults_counter = 0;
  int deads_counter = 0;

  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (!(i == 0 && j == 0)) {
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'E')? eggs_counter++ : 0;
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'L')? larvas_counter++ : 0;
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'P')? pupas_counter++ : 0;
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'A')? adults_counter++ : 0;
        (grid.getCell(posx + i, posy + j).getState()->getState() == 'D')? deads_counter++ : 0;

      }
    }
  }
  setEggsAmount(eggs_counter);
  setLarvasAmount(larvas_counter);
  setPupasAmount(pupas_counter);
  setAdultsAmount(adults_counter);
  setDeadsAmount(deads_counter);
}

State* StatePupa::nextState() {

 int sum_all = getAdultsAmount() + getPupasAmount() + getEggsAmount() + getDeadsAmount();

  if (getLarvasAmount() > sum_all){
    StateDead *state_dead;
    return state_dead;
  } else {
    StateAdult *state_adult;
    return state_adult;
  } 

}

int StatePupa::getLarvasAmount() const { return n_states_larva_; }
void StatePupa::setLarvasAmount(int value) { n_states_larva_ = value; }

int StatePupa::getEggsAmount() const { return n_states_egg_; }
void StatePupa::setEggsAmount(int value) {n_states_egg_ = value; }

int StatePupa::getPupasAmount() const { return n_states_pupa_; }
void StatePupa::setPupasAmount(int value) { n_states_pupa_ = value; }

int StatePupa::getAdultsAmount() const { return n_states_adult_; }
void StatePupa::setAdultsAmount(int value) { n_states_adult_ = value; }

int StatePupa::getDeadsAmount() const { return n_states_dead_; }
void StatePupa::setDeadsAmount(int value) { n_states_dead_ = value; }

const char StatePupa::getState() const {return 'P';}

#endif