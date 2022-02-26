#ifndef _CELLCPP_
#define _CELLCPP_
#include "Cell.hpp"
#include "Grid.hpp"

using namespace std;

Cell::Cell() {}

Cell::Cell(int posx, int posy, State state) {
  posx_ = posx;
  posy_ = posy;
  state_ = state;
}

State Cell::getState() const { return state_; }

State Cell::setState(State state) { state_ = state; }

void Cell::updateState() {
  /** TODO
   * CUENTA LOS VECINOS
   * ACTUALIZA EL ESTADO
   * RESETEA EL COUNTER DE VECINOS
   */
}

int Cell::neighbors(const Grid& grid) {
  /** TODO
   * CUENTA LOS VECINOS DE LA CÉLULA EN CUESTION
   * 
   */

}

ostream& Cell::operator<<(ostream& os, const Cell& cl){
  (cl.getState() == 0)? os <<  ' ': os << 'X';
  return os;
}

#endif