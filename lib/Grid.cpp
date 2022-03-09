#ifndef _GRIDCPP_
#define _GRIDCPP_

#include "Cell.hpp"
#include "Grid.hpp"

Grid::Grid() {}

Grid::Grid(int width, int height) {
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
}

const Cell& Grid::getCell(int posx, int posy) const { return board_[posx][posy]; }

void Grid::nextGeneration() {
  browseNeighbors();
  printGrid();
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

void Grid::printGrid(){
  cout << endl;
  for (int i = 0; i < board_.size(); i++) {
    for (int j = 0; j < board_[i].size(); j++){
      cout << getCell(i,j);
    }
    cout << endl;
  }
}

Cell& Grid::cellAcces(int i, int j) { return board_[i][j]; }

#endif
