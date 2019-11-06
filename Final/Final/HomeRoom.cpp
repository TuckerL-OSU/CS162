/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* HomeRoom.cpp
******************************************************************************/
#include "HomeRoom.hpp"

// initial location is at "center" of list
HomeRoom::HomeRoom(int Y, int X) {
	location = new Room(Y, X);
	location->roomName = "Clefairy Room";
	location->state = CLEFAIRY;
	location->north = nullptr;
	location->south = nullptr;
	location->east = nullptr;
	location->west = nullptr;
	metronome = 5;
}

HomeRoom::HomeRoom() {
	if (metronome > 0) {
		recover();
	}
}

HomeRoom::~HomeRoom() {
	delete location;
}