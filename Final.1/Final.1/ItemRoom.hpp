/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* ItemRoom.hpp
******************************************************************************/
#ifndef ItemRoom_hpp
#define ItemRoom_hpp
#include "Space.hpp"

class ItemRoom : public Space {
private:
	int moonStone;

public:
	ItemRoom();
	~ItemRoom();

	int event();

};


#endif // !ItemRoom_hpp
