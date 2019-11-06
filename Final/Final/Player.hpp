/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Player.hpp
******************************************************************************/
#ifndef Player_hpp
#define Player_hpp
#include "Backpack.hpp"
#include "Board.hpp"

class Player {
private:
	int y;
	int x;

public:
	Player();
	~Player();

	Backpack *bp;
	Space *location;
	int moonStones;

	void setLoc(int, int);
	void setY(int);
	int getY();
	void setX(int);
	int getX();
};

#endif // !Player_hpp
