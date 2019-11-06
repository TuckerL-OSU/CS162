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
	void moveResult(int);
	int questMenu();
	void turn();
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void action(int);

	int questLength;
	string north;
	string south;
	string east;
	string west;
	string inventory;
	Board *board;
	Player *ash;

public:
	Quest();
	~Quest();

	void mainMenu();

};


#endif // !Quest_hpp


