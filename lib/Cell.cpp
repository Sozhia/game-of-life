#ifndef _CELLCPP_
#define _CELLCPP_
#include "Cell.hpp"
#include "Grid.hpp"
#include "State.cpp"

State Cell::getState() const{}
State Cell::setState(State){}
void Cell::updateState(){}
int Cell::neighbors(const Grid&){}
ostream& Cell::operator<<(ostream&, const Cell&){}

#endif