#ifndef _GRIDWITHFROZENBORDERCPP_
#define _GRIDWITHFROZENBORDERCPP_

#include "GridWithFrozenBorder.hpp"
#include "Cell.hpp"

GridWithFrozenBorder::GridWithFrozenBorder(int width, int height, int shifts){
  board_.resize(width+2);
  for (int i = 0; i < board_.size(); i++) {
    board_[i].resize(height+2);
  }

  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++) {
      board_[i][j] = Cell(i,j);
    }
  }

  n_shifts_ = shifts;
}

Cell& GridWithFrozenBorder::cellAcces(int posx, int posy) { return board_[posx][posy]; }

const Cell& GridWithFrozenBorder::getCell(int posx, int posy) const{ return board_[posx][posy]; }

bool GridWithFrozenBorder::checkIfCellExist(int posx, int posy) const{
  try {
    getCell(posx, posy);
    return true;
  } catch (...){
    return false;
  }
}

const int GridWithFrozenBorder::getShifts() const {return n_shifts_;}

void GridWithFrozenBorder::nextGeneration(){
  browseNeighbors();
  updateStates();
}

void GridWithFrozenBorder::browseNeighbors() { 
  for (int i = 1; i < board_.size()-1; i++) {
    for (int j = 1; j < board_[i].size()-1; j++){
      getCell(i,j).getState()->neighbors(*this, i, j);
    }
  }
}

void GridWithFrozenBorder::updateStates(){
  for (int i = 1; i < board_.size()-1; i++) {
    for (int j = 1; j < board_[i].size()-1; j++){
      cellAcces(i,j).updateState();
    }
  }
}

void GridWithFrozenBorder::printGrid(){
  cout << endl;
  for (int j = 0; j < board_.size(); j++) {
    for (int i = 0; i < board_[j].size(); i++){
      cout <<"[" << getCell(i,j).getStateValue() << "]";
    }
    cout << endl;
  }
}


GridWithFrozenBorder::~GridWithFrozenBorder() {

} 


#endif