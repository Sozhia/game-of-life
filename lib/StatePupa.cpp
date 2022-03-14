#ifndef _STATEPUPACPP_
#define _STATEPUPACPP_

#include "StatePupa.hpp"

IState* StateLarva::nextState(std::vector<IState&> states_collection) {
  int num_larva_states = countStates('L', states_collection);
  int num_pupa_states = countStates('P', states_collection);
  int num_egg_states = countStates('E', states_collection);
  int num_adult_states = countStates('A', states_collection);
  int num_dead_states = countStates('D', states_collection);

  if ((num_larva_states > num_adult_states) ||
      (num_larva_states > num_dead_states)  ||
      (num_larva_states > num_pupa_states)  ||
      (num_larva_states > num_egg_states)) {
    return findState('D', states_collection);
  } else{
    return findState('A', states_collection);
  } 

}

int StateLarva::countStates(char letter, std::vector<IState&> states_collection) {
  int counter = 0;
  for (int i = 0; i < states_collection.size(); i++)
    (states_collection[i].getState() == letter)? counter++ : 0;
  
  return counter;
}

IState* StateLarva::findState(char letter, std::vector<IState&> states_collection){
  for (int i = 0; i < states_collection.size(); i++){
    if (states_collection[i].getState() == letter){
      return &states_collection[i];
      break;
    }
  }

}

char StateLarva::getState() const {return 'P';}

#endif