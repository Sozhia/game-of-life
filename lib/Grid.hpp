#ifndef _GRIDHPP_
#define _GRIDHPP_

#include <iostream>
#include <vector> 

class Cell;

class Grid{
 public:
  Grid();
  Grid(int, int);
  const Cell& getCell(int, int) const;
  void nextGeneration();

  void browseNeighbors();
  void quarterStates();

 private:
  std::vector<std::vector<Cell>> board_;
  unsigned int turn_;
};

#endif