#ifndef _STATEADULTCPP_
#define _STATEADULTCPP_

#include "StateAdult.hpp"

IState* StateAdult::nextState(std::vector<IState&> states_collection) {
  int num_adult_states = 0;

  num_adult_states = countStates('A', states_collection);

  if (num_adult_states > 0) {
    return findState('E', states_collection);
  } else{
    return findState('D', states_collection);
  } 

}

int StateAdult::countStates(char letter, std::vector<IState&> states_collection) {
  int counter = 0;
  for (int i = 0; i < states_collection.size(); i++)
    (states_collection[i].getState() == letter)? counter++ : 0;
  
  return counter;
}

IState* StateAdult::findState(char letter, std::vector<IState&> states_collection){
  for (int i = 0; i < states_collection.size(); i++){
    if (states_collection[i].getState() == letter){
      return &states_collection[i];
      break;
    }
  }

}

const char StateAdult::getState() const {return 'A';}

#endif