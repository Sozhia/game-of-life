#ifndef _STATELARVACPP_
#define _STATELARVACPP_

#include "StateLarva.hpp"

IState* StateLarva::nextState(std::vector<IState&> states_collection) {
  int num_larva_states = 0;
  int num_pupa_states = 0;
  int num_egg_states = 0;
  int num_adult_states = 0;
  int sum_adult_pupa_egg = 0;

  num_larva_states = countStates('L', states_collection);
  num_pupa_states = countStates('P', states_collection);
  num_egg_states = countStates('E', states_collection);
  num_adult_states = countStates('A', states_collection);

  sum_adult_pupa_egg = num_adult_states + num_pupa_states + num_egg_states;

  if (num_larva_states > sum_adult_pupa_egg){
    return findState('D', states_collection);
  } else{
    return findState('P', states_collection);
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

char StateLarva::getState() {return 'L';}

#endif