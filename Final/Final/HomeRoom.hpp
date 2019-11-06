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

public:
	HomeRoom(int, int);
	HomeRoom();
	~HomeRoom();

	int recover();
};


#endif // !HomeRoom_hpp
