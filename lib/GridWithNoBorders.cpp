#ifndef _GRIDWITHNOBORDERSCPP_
#define _GRIDWITHNOBORDERSCPP_

#include "GridWithNoBorders.hpp"
#include "Cell.hpp"

GridWithNoBorders::GridWithNoBorders(){}

GridWithNoBorders::GridWithNoBorders(int width, int height, int shifts){
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

void GridWithNoBorders::expandGrid(std::vector<std::vector<Cell>> &grid){

  std::vector<std::vector<Cell>> aux;

  aux.resize(board_.size() + 2);
  for (int i = 0; i < aux.size(); i++){
    aux[i].resize(board_[0].size() + 2);
    for (int j = 0; j < aux[i].size(); j++){
      aux[i][j] = Cell(i,j);
    }
  }

  for (int i = 1; i < aux.size()-1; i++) {
    for (int j = 1; j < aux[j].size()-1; j++){
      aux[i][j] = board_[i-1][j-1];
    }
  }

  grid = aux;
  
}

Cell& GridWithNoBorders::cellAcces(int posx, int posy) { return board_[posx][posy]; }

const Cell& GridWithNoBorders::getCell(int posx, int posy) const {return board_[posx][posy];}

const int GridWithNoBorders::getShifts() const {return n_shifts_;}

void GridWithNoBorders::nextGeneration(){
  if(neededToExpand())
    expandGrid(board_);
  browseNeighbors();
  updateStates();
}

void GridWithNoBorders::browseNeighbors() { 
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++){
      getCell(i,j).getState()->neighbors(*this, i, j);
    }
  }
}

void GridWithNoBorders::updateStates(){
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++){
      cellAcces(i,j).updateState();
    }
  }
}

void GridWithNoBorders::printGrid(){
  cout << endl;
  for (int j = 0; j < board_.size(); j++) {
    for (int i = 0; j < board_[i].size(); i++){
      cout <<"[" << getCell(i,j).getStateValue() << "]";
    }
    cout << endl;
  }
}

bool GridWithNoBorders::checkIfCellExist(int posx, int posy) const {
  try {
    getCell(posx, posy);
    return true;
  } catch (...){
    return false;
  }
}

bool GridWithNoBorders::neededToExpand(){
  bool flag = false;
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++){
      if(cellAcces(i,j).getStateValue() == 'X') {
        flag = true;
      }
    }
  }
  return flag;
}



GridWithNoBorders::~GridWithNoBorders() {

} 

#endif