/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Board.hpp
* Adapted from CS161 TicTacToe board
******************************************************************************/
#ifndef Board_hpp
#define Board_hpp
#include "Support.hpp"
#include "Space.hpp"
#include "HomeRoom.hpp"
#include "EmptyRoom.hpp"
#include "ItemRoom.hpp"
#include "RocketRoom.hpp"

// constants
// size of board
// odd numbers will allow you to start in dead center
const int ROWS = 5;
const int COLS = 5;

class Board {
public:
	Board();
	~Board();
	void setHome();
	void setRocket();
	void setMoonStones();
	bool checkMove(int, int);
	void move(int, int, Direction);
	void printBoard();
	Space* gameBoard[ROWS][COLS]; 

	int moonStones;
	int counter;


};

#endif // !Board_hpp
