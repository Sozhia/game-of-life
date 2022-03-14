#ifndef _STATEDEADCPP_
#define _STATEDEADCPP_

#include "StateDead.hpp"

IState* StateDead::nextState(std::vector<IState&> states_collection) {
  int num_adult_states = 0;

  num_adult_states = countStates('A', states_collection);

  if (num_adult_states >= 2){
    return findState('E', states_collection);
  } else{
    return findState('D', states_collection);
  } 

}

int StateDead::countStates(char letter, std::vector<IState&> states_collection) {
  int counter = 0;
  for (int i = 0; i < states_collection.size(); i++)
    (states_collection[i].getState() == letter)? counter++ : 0;
  
  return counter;
}

IState* StateDead::findState(char letter, std::vector<IState&> states_collection){
  for (int i = 0; i < states_collection.size(); i++){
    if (states_collection[i].getState() == letter){
      return &states_collection[i];
      break;
    }
  }

}

const char StateDead::getState() const {return 'D';}

#endif