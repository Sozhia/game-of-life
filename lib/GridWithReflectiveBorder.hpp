#ifndef _GRIDWITHREFLECTIVEBORDERHPP_
#define _GRIDWITHREFLECTIVEBORDERHPP_

#include "Grid.hpp"
#include "Cell.hpp"
#include <vector> 

class GridWithReflectiveBorder : public Grid {

 public: 

  GridWithReflectiveBorder();
  GridWithReflectiveBorder(int, int, int);
  
  Cell& cellAcces(int, int);
  const Cell& getCell(int, int) const;

  bool checkIfCellExist(int, int) const;

  void nextGeneration();
  const int getShifts() const;

  void browseNeighbors();
  void updateStates();
  void printGrid();
  
  ~GridWithReflectiveBorder();


 private:
  std::vector<std::vector<Cell>> board_;
  int n_shifts_;
};
#endif