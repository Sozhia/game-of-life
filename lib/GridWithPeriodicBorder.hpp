#ifndef _GRIDWITHPERIODICBORDERHPP_
#define _GRIDWITHPERIODICBORDERHPP_

#include "Grid.hpp"
#include "Cell.hpp"
#include <vector> 

class GridWithPeriodicBorder : public Grid {

 public: 
  
  GridWithPeriodicBorder();
  GridWithPeriodicBorder(int, int, int);

  bool checkIfCellExist(int, int) const;
  
  Cell& cellAcces(int, int);
  const Cell& getCell(int, int) const;
  const int getShifts() const;


  void nextGeneration();
  void browseNeighbors();
  void updateStates();
  void printGrid();
  
  ~GridWithPeriodicBorder();


 private:
  std::vector<std::vector<Cell>> board_;
  int n_shifts_;
};
#endif