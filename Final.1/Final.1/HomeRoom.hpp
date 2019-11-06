/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* HomeRoom.hpp
******************************************************************************/
#ifndef HomeRoom_hpp
#define HomeRoom_hpp
#include "Space.hpp"

class HomeRoom : public Space {
private:
	int metronome;
	int returned;

public:
	HomeRoom();
	~HomeRoom();

	int event();
};


#endif // !HomeRoom_hpp
