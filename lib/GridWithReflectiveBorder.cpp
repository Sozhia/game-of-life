#ifndef _GRIDWITHREFLECTIVEBORDERCPP_
#define _GRIDWITHREFLECTIVEBORDERCPP_

#include "GridWithReflectiveBorder.hpp"
#include "Cell.hpp"

GridWithReflectiveBorder::GridWithReflectiveBorder(int width, int height, int shifts){
  board_.resize(width);
  for (int i = 0; i < board_.size(); i++) {
    board_[i].resize(height);
  }

  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++) {
      board_[i][j] = Cell(i,j);
    }
  }

  n_shifts_ = shifts;
}
Cell& GridWithReflectiveBorder::cellAcces(int posx, int posy) { 
  if (posx < 0) {
    posx = 0;
  } else if(posx >= board_.size()) {
    posx = board_.size()-1;
  }

  if (posy < 0) {
    posy = 0;
  } else if(posy >= board_[0].size()) {
    posy = board_[0].size()-1;
  }
  return board_[posx][posy]; 
}

const int GridWithReflectiveBorder::getShifts() const {return n_shifts_;}

const Cell& GridWithReflectiveBorder::getCell(int posx, int posy) const {
  if (posx < 0) {
    posx = 0;
  } else if(posx >= board_.size()) {
    posx = board_.size()-1;
  }

  if (posy < 0) {
    posy = 0;
  } else if(posy >= board_[0].size()) {
    posy = board_[0].size()-1;
  } 
  return board_[posx][posy]; 
}

void GridWithReflectiveBorder::nextGeneration(){
  browseNeighbors();
  updateStates();
}

void GridWithReflectiveBorder::browseNeighbors() { 
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[0].size(); j++){
      getCell(i,j).getState()->neighbors(*this, i, j);
    }
  }
}

void GridWithReflectiveBorder::updateStates() {
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++) {
        cellAcces(i,j).updateState();
    }
  }
}

bool GridWithReflectiveBorder::checkIfCellExist(int posx, int posy) const{
  try {
    getCell(posx, posy);
    return true;
  } catch (...){
    return false;
  }
}

void GridWithReflectiveBorder::printGrid(){
  cout << endl;
  for (int j = 0; j < board_.size(); j++) {
    for (int i = 0; i < board_[j].size(); i++){
      cout <<"[" << getCell(i,j).getStateValue() << "]";
    }
    cout << endl;
  }
}

GridWithReflectiveBorder::~GridWithReflectiveBorder() {} 


#endif