#include "./lib/Grid.hpp"
#include "./lib/Cell.hpp"

#include <string.h>
#include <stdio.h>

void printHelp();
void gameParameters();
void gameStart(int rows, int columns, int shifts);
void printGame(Grid &board, int counter);
State* transferStatus(char letter);
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
  std::cout << "\t Please enter the number of cells, you want to modify."<<std::endl;
  std::cout << "Otherwise press Ctrl + C to exit."<< std::endl;
  cin >> aux;
  for (int i = 0; i < aux; i++) {
    int posx, posy;
    char status;
    std::cout << "\t Please enter the X coordinate of alive cell, otherwise press Ctrl + C to exit."<< std::endl;
    cin >> posx;
    std::cout << "\t Please enter the Y coordinate of alive cell, otherwise press Ctrl + C to exit."<< std::endl;
    cin >> posy;
    std::cout << "\t Please enter one of the followin letters in brackets "<< std::endl;
    std::cout << "\t (A)dults ; (E)ggs ; (L)arvas ; (P)upas"<< std::endl;
    cin >> status;
    grid.cellAcces(posx+1,posy+1).setState(transferStatus(status));
  }
}

void printHelp() {
    std::cout << "This is a implementation of The Game of Life by the British mathematician John Horton Conway in 1970"<< std::endl;
    std::cout << "in the C++ programming language for academic purposes."<< std::endl;
    std::cout << "To run the program in your local machine check out the following steps:"<< std::endl;
    std::cout << "\t 1.- ./nfa_simulation "<< std::endl;
    std::cout << "\t 2.- You must enter the grid size manually (NxM) and the number of shifts"<< std::endl;
    std::cout << "\t \t 2.1.- The program expects non negative numbers."<< std::endl;
    std::cout << "\t 3.- Enter in sequence the X and Y coordinates of the cells you want to modify state value. "<< std::endl;
    std::cout << "\t 4.- Press any key to see an step by step evolution of the grid."<< std::endl;
}

void printGame(Grid &board, int counter) {
  std::cout << "Shift: " << counter << std::endl;
  board.printGrid();
  board.nextGeneration();
  std::cout << "\t Press Enter key to step forward . . . "<< std::endl;
}

State* transferStatus(char letter) {
  switch(letter){
    case 'A':
      StateAdult *state_adult;
      return state_adult;
      break;
     
    case 'D':
      StateDead *state_dead;
      return state_dead;
      break;

    case 'E':
      StateEgg *state_egg;
      return state_egg;
      break;

    case 'L':
      StateLarva *state_larva;
      return state_larva;
      break;

    case 'P':
      StatePupa *state_pupa;
      return state_pupa;
      break;

    default:
      StateDead *state_dead_def;
      return state_dead_def;
      break;
  }
}