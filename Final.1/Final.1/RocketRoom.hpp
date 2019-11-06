/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* RocketRoom.hpp
******************************************************************************/
#ifndef RocketRoom_hpp
#define RocketRoom_hpp
#include "Space.hpp"

class RocketRoom : public Space {
public:
	RocketRoom();
	~RocketRoom();

	int moonStonesNeeded;
	int event();

};

#endif // !RocketRoom_hpp
