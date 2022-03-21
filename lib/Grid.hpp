#ifndef _GRIDHPP_
#define _GRIDHPP_

#include "Cell.hpp"

class Cell;

class Grid{
 public:
  virtual Cell& cellAcces(int, int) = 0;
  virtual const Cell& getCell(int, int) const = 0;
  virtual bool checkIfCellExist(int, int) const = 0;
  virtual const int getShifts() const = 0;
  virtual void nextGeneration() = 0;
  virtual void browseNeighbors() = 0;
  virtual void updateStates() = 0;
  virtual void printGrid() = 0;
  virtual ~Grid() {}; 
};

#endif