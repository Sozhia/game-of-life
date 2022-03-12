#ifndef _GRIDCPP_
#define _GRIDCPP_

#include "Cell.hpp"
#include "Grid.hpp"

Grid::Grid() {}

Grid::Grid(int width, int height, int shifts) {
  board_.resize(width+2);
  for (int i = 0; i < board_.size(); i++){
    board_[i].resize(height+2);
    for (int j = 0; j < board_[i].size(); j++){
      Cell cell;
      board_[i][j] = cell;
      cellAcces(i,j).setPosx(i);
      cellAcces(i,j).setPosY(j);
    }
  }
  setShifts(shifts);
}

void Grid::nextGeneration() {
  browseNeighbors();
  updateStates();
}

void Grid::browseNeighbors() {
  for (int i = 1; i < board_.size()-1; i++) {
    for (int j = 1; j < board_[i].size()-1; j++){
      int neighbors = cellAcces(i,j).neighbors(*this);
      cellAcces(i,j).setAliveNeighbors(neighbors);
    }
  }
}

void Grid::updateStates(){
  for (int i = 1; i < board_.size()-1; i++) {
    for (int j = 1; j < board_[i].size()-1; j++){
      cellAcces(i,j).updateState();
    }
  }
}

int Grid::getAliveCells(){
  int counter = 0;

  for (int i = 1; i < board_.size()-1; i++) {
    for (int j = 1; j < board_[i].size()-1; j++){
      if(getCell(i,j).getState() == 1){
        counter++;
      }
    }
  }
  return counter;
}

int Grid::getDeadCells(){
  return ((board_.size()-2) * (board_[0].size()-2))  - getAliveCells();
}

void Grid::printGrid(){
  cout << endl;
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++){
      cout << getCell(i,j);
    }
    cout << endl;
  }
}

const Cell& Grid::getCell(int posx, int posy) const { return board_[posx][posy]; }

int Grid::getShifts() {return shifts_; }

void Grid::setShifts(int value){shifts_ = value;}

Cell& Grid::cellAcces(int i, int j) { return board_[i][j]; }

#endif
