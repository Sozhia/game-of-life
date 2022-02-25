#ifndef _GRIDHPP_
#define _GRIDHPP_

#include <iostream>

class Cell;

class Grid{
 public:
  const Cell& Grid::getCell(int, int) const;
  void Grid::nextGeneration();
};

#endif