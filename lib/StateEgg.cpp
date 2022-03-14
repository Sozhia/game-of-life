#ifndef _STATEEGGCPP_
#define _STATEEGGCPP_

#include "StateEgg.hpp"

IState* StateEgg::nextState(std::vector<IState&> states_collection) {
  int num_larva_states = 0;
  int num_egg_states = 0;
  num_larva_states = countStates('L', states_collection);
  num_egg_states = countStates('E', states_collection);

  if (num_larva_states > num_egg_states){
    return findState('D', states_collection);
  } else{
    return findState('L', states_collection);
  } 

}

int StateEgg::countStates(char letter, std::vector<IState&> states_collection) {
  int counter = 0;
  for (int i = 0; i < states_collection.size(); i++)
    (states_collection[i].getState() == letter)? counter++ : 0;
  
  return counter;
}

IState* StateEgg::findState(char letter, std::vector<IState&> states_collection){
  for (int i = 0; i < states_collection.size(); i++){
    if (states_collection[i].getState() == letter){
      return &states_collection[i];
      break;
    }
  }

}

char StateEgg::getState() {return 'E';}

#endif