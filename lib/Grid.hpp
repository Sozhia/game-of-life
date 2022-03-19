#ifndef _GRIDHPP_
#define _GRIDHPP_

#include <iostream>
#include <vector> 
#include "Cell.hpp"

class Cell;

class Grid{
 public:
  virtual Cell& Grid::cellAcces(int, int) = 0;
  virtual const Cell& Grid::getCell(int, int) const = 0;
  void nextGeneration();
  virtual Grid::~Grid() {}; 

 private:
  std::vector<std::vector<Cell>> board_;
  int shifts_;
};

#endif