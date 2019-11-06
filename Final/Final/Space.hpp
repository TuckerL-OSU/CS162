/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Space.hpp
******************************************************************************/
#ifndef Space_hpp
#define Space_hpp
#include "Support.hpp"

enum SpaceState {
	CLEFAIRY = 'C',
	ROCKET = 'R',
	CURRENT = '@',
	UNVISITED = ' ',
	VISITED = 'X'
};

enum Direction {
	// direction moved 
	NORTH = '^',
	SOUTH = 'v',
	EAST = '>',
	WEST = '<'
};

class Space {
protected:
	string roomName;
	Space *north; // top
	Space *south; // bottom
	Space *east; // right
	Space *west; // left
	
public:
	Space();
	~Space();

	SpaceState state;


	//virtual Room* generateRoom() = 0;
	virtual void printRoom() = 0;
	Space* move(Direction);
	void setNorth(Space*);
	Space* getNorth();
	void setSouth(Space*);
	Space* getSouth();
	void setEast(Space*);
	Space* getEast();
	void setWest(Space*);
	Space* getWest();

};

#endif /* Space_hpp */
