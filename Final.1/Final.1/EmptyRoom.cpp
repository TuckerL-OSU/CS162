/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* EmptyRoom.cpp
******************************************************************************/
#include "EmptyRoom.hpp"
#include "Space.hpp"

EmptyRoom::EmptyRoom() {
	this->state = UNVISITED;
}

EmptyRoom::~EmptyRoom() {

}

int EmptyRoom::event() {
	int findRock = 0; 
	this->state = VISITED;

	findRock = RNG(1, 10);
	// 50% chance to find a rock in an empty room
	if (findRock >= 1 && findRock < 6) {
		cout << "This Room is full of sparkly Rocks!" << endl;
		cout << "You're not sure if they are MoonStones, but you take one anyway." << endl;
		return 1;
	}
	else {
		return 0;
	}
}