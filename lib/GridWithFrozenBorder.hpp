#ifndef _GRIDWITHFROZENBORDERHPP_
#define _GRIDWITHFROZENBORDERHPP_

#include "Grid.hpp"
#include "Cell.hpp"
#include <vector> 

class GridWithFrozenBorder : public Grid {

 public: 
  GridWithFrozenBorder(int, int, int);

  Cell& cellAcces(int, int);
  const Cell& getCell(int, int) const;
  bool checkIfCellExist(int, int) const;

  const int getShifts() const;

  void nextGeneration();
  void browseNeighbors();
  void updateStates();
  void printGrid();
  ~GridWithFrozenBorder();

 private:
  std::vector<std::vector<Cell>> board_;
  int n_shifts_;

};
#endif