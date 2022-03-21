#ifndef _GRIDWITHPERIODICBORDERCPP_
#define _GRIDWITHPERIODICBORDERCPP_

#include "GridWithPeriodicBorder.hpp"
#include "Cell.hpp"

GridWithPeriodicBorder::GridWithPeriodicBorder(int width, int height, int shifts){
  board_.resize(width);
  for (int i = 0; i < board_.size(); i++){
    board_[i].resize(height);
    for (int j = 0; j < board_[i].size(); j++){
      Cell cell(i,j);
      board_[i][j] = cell;
    }
  }
  n_shifts_ = shifts;
}

Cell& GridWithPeriodicBorder::cellAcces(int posx, int posy) { 
  if ( posx < 0 ) {
    posx = board_.size()-1;
  } else if( posx >= board_.size() ) {
    posx = 0 ;
  }

  if ( posy < 0 ) {
    posy = board_[0].size()-1;
  } else if( posy >= board_[0].size() ) {
    posy = 0;
  }

  return board_[posx][posy]; 
}

const int GridWithPeriodicBorder::getShifts() const {return n_shifts_;}

const Cell& GridWithPeriodicBorder::getCell(int posx, int posy) const {
  if ( posx < 0 ) {
    posx = board_.size()-1;
  } else if( posx >= board_.size() ) {
    posx = 0 ;
  }

  if ( posy < 0 ) {
    posy = board_[0].size()-1;
  } else if( posy >= board_[0].size() ) {
    posy = 0;
  }

  return board_[posx][posy]; 
}

void GridWithPeriodicBorder::nextGeneration(){
  browseNeighbors();
  updateStates();
}

void GridWithPeriodicBorder::browseNeighbors() { 
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++){
        getCell(i,j).getState()->neighbors(*this, i, j);
    }
  }
}

void GridWithPeriodicBorder::updateStates() {
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 1; j < board_[i].size(); j++) {
        cellAcces(i,j).updateState();
    }
  }
}

bool GridWithPeriodicBorder::checkIfCellExist(int posx, int posy) const{
  try {
    getCell(posx, posy);
    return true;
  } catch (...){
    return false;
  }
}

void GridWithPeriodicBorder::printGrid(){
   cout << endl;
  for (int j = 0; j < board_.size(); j++) {
    for (int i = 0; i < board_[j].size(); i++){
      cout <<"[" << getCell(i,j).getStateValue() << "]";
    }
    cout << endl;
  }
}

GridWithPeriodicBorder::~GridWithPeriodicBorder() {

} 


#endif