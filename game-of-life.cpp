#include "./lib/Grid.hpp"
#include "./lib/GridWithOpenBorder.hpp"
#include "./lib/GridWithFrozenBorder.hpp"
#include "./lib/GridWithPeriodicBorder.hpp"
#include "./lib/GridWithReflectiveBorder.hpp"
#include "./lib/StateDead.hpp"
#include "./lib/StateAlive.hpp"
#include <string.h>
#include <stdio.h>

Grid* askGameSettings();
void gameStart(Grid* grid);

int askRows();
int askColumns();
int askShifts();
char askTypeOfGrid();
Grid* gridGenerator(char letter);
void askAliveCells(Grid* grid);

void printGame(Grid* board, int counter);
void printHelp();

int main(int argc, char** argv) {
  if (argc == 2 && strcmp(argv[1], "--help")==0) {
		printHelp();
		exit(1);
	}
  if (argc != 1) {
    std::cout << "\t Try ./game-of-life --help for more information."<< std::endl;
    exit(1);
	} else {
    gameStart(askGameSettings());
  }
  return 0;
}


Grid* askGameSettings() {
  char letter = askTypeOfGrid();
  Grid* board = gridGenerator(letter);
  askAliveCells(board);
  return board;
}

int askRows() {
  int aux;
  std::cout << "\t Please enter the number of Rows (M), otherwise press Ctrl + C to exit."<< std::endl;
  cin >> aux;
  return aux;
}

int askColumns() {
  int aux;
  std::cout << "\t Please enter the number of Columns (N), otherwise press Ctrl + C to exit."<< std::endl;
  cin >> aux;
  return aux;
}

int askShifts() {
  int aux;
  std::cout << "\t Please enter the number of Shifts, otherwise press Ctrl + C to exit."<< std::endl;
  cin >> aux;
  return aux;
}

char askTypeOfGrid() {
  char aux;
  std::cout << "\t Please enter the type of Grid."<< std::endl;
  std::cout << "\t (F)rozen ; (O)pen ; (P)eriodic ; (R)eflective " << std::endl;
  std::cout << "\t Otherwise press Ctrl + C to exit."<< std::endl;
  cin >> aux;
  return aux;
}

void askAliveCells(Grid* grid) {
  int aux;
  std::cout << "\t Please enter the number of cells, you want to se as Alive."<<std::endl;
  std::cout << "Otherwise press Ctrl + C to exit."<< std::endl;
  cin >> aux;
  for (int i = 0; i < aux; i++) {
    int posx, posy;
    std::cout << "\t Please enter the X coordinate of alive cell, otherwise press Ctrl + C to exit."<< std::endl;
    cin >> posx;
    std::cout << "\t Please enter the Y coordinate of alive cell, otherwise press Ctrl + C to exit."<< std::endl;
    cin >> posy;
    State* state;
    state = new StateAlive;
    try {
      grid ->cellAcces(posx, posy).setState(state);
    } catch (...){
      std::cout << "\t No Cell detect at: "<< posx+ " "<< posy+ ". Skipped"<< std::endl;
    }
  }
}

void gameStart(Grid* grid) {
  for (unsigned int counter = 0; counter < grid->getShifts(); counter ++) {
    printGame(grid, counter);
    getchar();
  }
}

void printHelp() {
    std::cout << "This is a implementation of The Game of Life by the British mathematician John Horton Conway in 1970"<< std::endl;
    std::cout << "in the C++ programming language for academic purposes."<< std::endl;
    std::cout << "To run the program in your local machine check out the following steps:"<< std::endl;
    std::cout << "\t 1.- ./game-of-life "<< std::endl;
    std::cout << "\t 2.- You must enter the grid size manually (NxM) and the number of shifts"<< std::endl;
    std::cout << "\t \t 2.1.- The program expects non negative numbers."<< std::endl;
    std::cout << "\t 3.- Enter in sequence the X and Y coordinates of the cells you want to modify state value. "<< std::endl;
    std::cout << "\t 4.- Press any key to see an step by step evolution of the grid."<< std::endl;
}

void printGame(Grid* board, int counter) {
  std::cout << "Shift: " << counter << std::endl;
  board->printGrid();
  board->nextGeneration();
  std::cout << "\t Press Enter key to step forward . . . "<< std::endl;
}

Grid* gridGenerator(char letter) {
  Grid* grid;
  int rows, columns, shifts;
  std::cout << "\t Please enter the grid size (NxM) and shifts manually, otherwise press Ctrl + C to exit."<< std::endl;
  columns = askColumns();
  rows = askRows();
  shifts = askShifts();
  switch(letter){
    case 'O':
      grid = new GridWithOpenBorder(rows, columns, shifts);
      break;
     
    case 'F':
      grid = new GridWithFrozenBorder(rows, columns, shifts);
      break;

    case 'P':
      grid = new GridWithPeriodicBorder(rows, columns, shifts);
      break;

    case 'R':
      grid = new  GridWithReflectiveBorder(rows, columns, shifts);
      break;

    default:
       grid = new GridWithFrozenBorder(rows, columns, shifts);
      break;
  }
  return grid;
}