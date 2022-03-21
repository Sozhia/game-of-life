#ifndef _GRIDWITHOPENBORDERHPP_
#define _GRIDWITHOPENBORDERHPP_

#include "Grid.hpp"
#include "Cell.hpp"
#include <vector> 

class GridWithOpenBorder : public Grid {

 public: 

  GridWithOpenBorder();
  GridWithOpenBorder(int, int, int);
  
  bool checkIfCellExist(int, int) const;
  Cell& cellAcces(int, int);
  const Cell& getCell(int, int) const;

  const int getShifts() const;

  void nextGeneration();
  void browseNeighbors();
  void updateStates();
  void printGrid();
  
  ~GridWithOpenBorder();


 private:
  std::vector<std::vector<Cell>> board_;
  int n_shifts_;
};
#endif