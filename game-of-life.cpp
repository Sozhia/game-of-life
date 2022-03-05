#include "./lib/Grid.hpp"
#include "./lib/Cell.hpp"
#include <string.h>
#include <stdio.h>

void printHelp();
void gameParameters();
void gameStart(int, int);

int askWidth();
int askHeight();

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

void printHelp() {
    std::cout << "This is a implementation of The Game of Life by the British mathematician John Horton Conway in 1970"<< std::endl;
    std::cout << "in the C++ programming language for academic purposes."<< std::endl;
    std::cout << "To run the program in your local machine check out the following steps:"<< std::endl;
    std::cout << "\t 1.- ./nfa_simulation "<< std::endl;
    std::cout << "\t 2.- You must enter the grid size manually (NxM)"<< std::endl;
    std::cout << "\t \t 2.1.- The program expects non negative numbers, otherwise will exit."<< std::endl;
    std::cout << "\t 3.- Enter in sequence the X and Y coordinates of the alive cells. "<< std::endl;
    std::cout << "\t 4.- Press any key to see an step by step evolution of the grid."<< std::endl;
  }

void gameParameters() {
  int height,width;
  std::cout << "\t Please enter the grid size manually (NxM), otherwise press 0 to exit."<< std::endl;

  width = askWidth();
  if (width > 0) {
    height = askHeight();
    if (height > 0) {
      gameStart(width, height);
    }
  } else {
    std::cout << "\t Exiting program."<< std::endl;
  }

}

int askWidth() {
    int aux;
    std::cout << "\t Please enter the width of the grid (N), otherwise press 0 to exit."<< std::endl;
    cin >> aux;
    return aux;
}

int askHeight() {
    int aux;
    std::cout << "\t Please enter the height of the grid (M), otherwise press 0 to exit."<< std::endl;
    cin >> aux;
    return aux;
}

void gameStart(int width, int height){
  Grid grid(width,height);
  std::cout << "Enter in sequence the X and Y coordinates of the alive cells, then enter value -1 to begin "<< std::endl;
  int xvalue, yvalue, turns;
  std::cout << "Enter the maxim number of turns:"<< std::endl;
  cin >> turns;
  do{
    xvalue = 0;
    yvalue = 0;
    std::cout << "\t Enter non negative number for X coordinate (default 0):"<< std::endl;
    cin >> xvalue;
    std::cout << "\t Enter non negative number for Y coordinate (default 0):"<< std::endl;
    cin >> yvalue;
    grid.cellAcces(xvalue,yvalue).setState(1);
  }while((xvalue >= 0) || (yvalue >= 0));

  do {
    grid.nextGeneration();
  }while (grid.getTurn() < turns);

}