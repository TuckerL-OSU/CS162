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
	MOONSTONE = 'X',
	UNVISITED = ' ',
	VISITED = ' '
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
	//Space *north; // top
	//Space *south; // bottom
	//Space *east; // right
	//Space *west; // left
	
public:
	Space();
	~Space();

	SpaceState state;

	virtual int event() = 0;

};

#endif /* Space_hpp */
