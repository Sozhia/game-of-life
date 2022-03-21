#ifndef _GRIDWITHFROZENBORDERCPP_
#define _GRIDWITHFROZENBORDERCPP_

#include "GridWithOpenBorder.hpp"
#include "Cell.hpp"

GridWithOpenBorder::GridWithOpenBorder(){}

GridWithOpenBorder::GridWithOpenBorder(int width, int height, int shifts){
  board_.resize(width);
  for (int i = 0; i < board_.size(); i++){
    board_[i].resize(height);
    for (int j = 0; j < board_[i].size(); j++){
      board_[i][j] = Cell(i,j);
    }
  }
  n_shifts_ = shifts;
}

Cell& GridWithOpenBorder::cellAcces(int posx, int posy) { return board_[posx][posy]; }

const Cell& GridWithOpenBorder::getCell(int posx, int posy) const { return board_[posx][posy]; }

const int GridWithOpenBorder::getShifts() const {return n_shifts_;}

void GridWithOpenBorder::nextGeneration(){
  browseNeighbors();
  updateStates();
}

void GridWithOpenBorder::browseNeighbors() { 
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++){
      getCell(i,j).getState()->neighbors(*this, i, j);
    }
  }
}

void GridWithOpenBorder::updateStates(){
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++){
      cellAcces(i,j).updateState();
    }
  }
}

void GridWithOpenBorder::printGrid(){
  cout << endl;
  for (int j = 0; j < board_.size(); j++) {
    for (int i = 0; j < board_[i].size(); i++){
      cout << getCell(i,j).getStateValue();
    }
    cout << endl;
  }
}

bool GridWithOpenBorder::checkIfCellExist(int posx, int posy) const {
  try {
    getCell(posx, posy);
    return true;
  } catch (...){
    return false;
  }
}

GridWithOpenBorder::~GridWithOpenBorder() {

} 


#endif