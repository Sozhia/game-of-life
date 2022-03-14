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

  const int getShifts() const;
  void setShifts(int);

 private:
  std::vector<std::vector<Cell>> board_;
  int shifts_;
};

#endif