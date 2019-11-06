/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 1: Langton's Ant Simulation
* Ant.hpp
******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

enum SlotState {
	WHITE = ' ',
	BLACK = '#'
};

class Ant {
private:
	SlotState **board;
	int numRows;
	int numCols;
	int numOfSteps;
	int posRow;
	int posCol;

	void move();
	void toggleSlot();
	void turnLeft(int &, int &);
	void turnRight(int &, int &);
	void printBoard();
	void clearBoard();

public:
	Ant(int, int, int, int, int);
	~Ant();
	void start();
};

#endif