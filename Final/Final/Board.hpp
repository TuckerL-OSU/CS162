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
#include "Cave.hpp"

// constants
// size of board
// odd numbers will allow you to start in dead center
const int ROWS = 5;
const int COLS = 5;

class Board {
private:
	Space *head;

public:
	Board();
	~Board();
	void addSpace();
	void setHome();
	void setRocket();
	int move(int, int, Direction);
	void printBoard();
	//SpaceState gameBoard[ROWS][COLS];
	Space **gameBoard;

};

#endif // !Board_hpp
