/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* EmptyRoom.hpp
******************************************************************************/
#ifndef EmptyRoom_hpp
#define EmptyRoom_hpp
#include "Space.hpp"

class EmptyRoom : public Space {
public:
	EmptyRoom();
	~EmptyRoom();

	int event();

};

#endif // !EmptyRoom_hpp
