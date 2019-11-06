/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Quest.hpp
******************************************************************************/
#ifndef Quest_hpp
#define Quest_hpp
#include "Board.hpp"
//#include "Backpack.hpp"
#include "Player.hpp"

class Quest {
private:
	bool moveResult(bool);
	int questMenu();
	void turn();
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void action(int);
	void encounter(int, int);

	int questLength;
	int moonStonesFound;
	bool success;
	string north;
	string south;
	string east;
	string west;
	string inventory;
	Board *board;
	Player *ash;
	bool validMove;

public:
	Quest();
	~Quest();

	void mainMenu();

};


#endif // !Quest_hpp


