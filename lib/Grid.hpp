#ifndef _GRIDHPP_
#define _GRIDHPP_

#include <iostream>
#include <vector> 

class Cell;

class Grid{
 public:
  Grid();
  Grid(int, int, int);
  const Cell& getCell(int, int) const;
  void nextGeneration();
  Cell& cellAcces(int, int);
  void browseNeighbors();
  void updateStates();
  void printGrid();
  int getShifts();
  void setShifts(int);
  int getAliveCells();
  int getDeadCells();

 private:
  std::vector<std::vector<Cell>> board_;
  int shifts_;
};

#endif