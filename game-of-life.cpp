#include "./lib/Grid.hpp"
#include "./lib/Cell.hpp"

#include <string.h>
#include <stdio.h>
#include <assert.h>

void printHelp();
void gameParameters();
void gameStart(int rows, int columns, int shifts);
void printGame(Grid &board, int counter);
int askRows();
int askColumns();
int askShifts();
void askAliveCells(Grid& grid);

int main(int argc, char** argv) {
  if (argc == 2 && strcmp(argv[1], "--help")==0) {
		printHelp();
		exit(1);
	}
  if (argc != 1) {
    std::cout << "\t Try ./game-of-life --help for more information."<< std::endl;
    exit(1);
	} else {
    gameParameters();
  }
  return 0;
}


void gameParameters() {
  int rows, columns, shifts;
  std::cout << "\t Please enter the grid size (NxM) and shifts manually, otherwise press Ctrl + C to exit."<< std::endl;
  columns = askColumns();
  rows = askRows();
  shifts = askShifts();
  gameStart(rows, columns, shifts);
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

void gameStart(int rows, int columns, int shifts) {
  Grid board(columns,rows, shifts);
  askAliveCells(board);
  for (unsigned int counter = 0; counter < board.getShifts(); counter ++) {
    printGame(board, counter);
    getchar();
  }
  
}

void askAliveCells(Grid& grid) {
  int aux;
  std::cout << "\t Please enter the number of alive cells, otherwise press Ctrl + C to exit."<< std::endl;
  cin >> aux;
  for (int i = 0; i < aux; i++) {
    int posx, posy;
    std::cout << "\t Please enter the X coordinate of alive cell, otherwise press Ctrl + C to exit."<< std::endl;
    cin >> posx;
    std::cout << "\t Please enter the Y coordinate of alive cell, otherwise press Ctrl + C to exit."<< std::endl;
    cin >> posy;
    grid.cellAcces(posx+1,posy+1).setState(1);
  }
}

void printHelp() {
    std::cout << "This is a implementation of The Game of Life by the British mathematician John Horton Conway in 1970"<< std::endl;
    std::cout << "in the C++ programming language for academic purposes."<< std::endl;
    std::cout << "To run the program in your local machine check out the following steps:"<< std::endl;
    std::cout << "\t 1.- ./nfa_simulation "<< std::endl;
    std::cout << "\t 2.- You must enter the grid size manually (NxM) and the number of shifts"<< std::endl;
    std::cout << "\t \t 2.1.- The program expects non negative numbers."<< std::endl;
    std::cout << "\t 3.- Enter in sequence the X and Y coordinates of the alive cells. "<< std::endl;
    std::cout << "\t 4.- Press any key to see an step by step evolution of the grid."<< std::endl;
}

void printGame(Grid &board, int counter) {
  std::cout << "Shift: " << counter << std::endl;
  board.printGrid();
  std::cout << "Alive cells: " << board.getAliveCells() << std::endl;
  std::cout << "Dead cells: " << board.getDeadCells() << std::endl;
  board.nextGeneration();
  std::cout << "\t Press Enter key to step forward . . . "<< std::endl;
}