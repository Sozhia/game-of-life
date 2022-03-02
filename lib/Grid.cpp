#ifndef _GRIDCPP_
#define _GRIDCPP_
#include "Cell.hpp"
#include "Grid.hpp"

Grid::Grid(){}
Grid::Grid(int width, int height){
  turn_ = 0;
  board_.resize(width+2);
  for (int i = 0; i < board_.size(); i++){
    board_[i].resize(height+2);
    for (int j = 0; j < board_[i].size(); j++){
      Cell cell;
      board_[i][j] = cell;
    }
  }
}

const Cell& Grid::getCell(int i, int j) const {return board_[i][j];}

void Grid::nextGeneration(){
  browseNeighbors();
  quarterStates();
  cout << turn_;
  printGrid();
  turn_++;
}

void Grid::browseNeighbors(){
  for (int i = 1; i < board_.size()-1; i++) {
    for (int j = 1; j < board_[i].size()-1; j++){
      board_[i][j].neighbors(*this);
    }
  }
}

void Grid::quarterStates(){
  for (int i = 1; i < board_.size()-1; i++) {
    for (int j = 1; j < board_[i].size()-1; j++){
      board_[i][j].updateState();
    }
  }
}

void Grid::printGrid(){
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++){
      cout << getCell(i,j); 
    }
  }
}

#endif