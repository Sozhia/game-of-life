#ifndef _GRIDWITHNOBORDERSHPP_
#define _GRIDWITHNOBORDERSHPP_

#include "Grid.hpp"
#include "Cell.hpp"
#include <vector> 

class GridWithNoBorders : public Grid {

 public: 

  GridWithNoBorders();
  GridWithNoBorders(int, int, int);

  void expandGrid(std::vector<std::vector<Cell>> &grid);
  
  bool checkIfCellExist(int, int) const;
  bool neededToExpand();

  Cell& cellAcces(int, int);
  const Cell& getCell(int, int) const;

  const int getShifts() const;

  void nextGeneration();
  void browseNeighbors();
  void updateStates();
  void printGrid();
  
  ~GridWithNoBorders();


 private:
  std::vector<std::vector<Cell>> board_;
  int n_shifts_;
};
#endif