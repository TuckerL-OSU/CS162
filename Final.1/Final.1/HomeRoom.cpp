/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* HomeRoom.cpp
******************************************************************************/
#include "HomeRoom.hpp"

HomeRoom::HomeRoom() {
	this->state = CLEFAIRY;
	this->metronome = 5;
	this->returned = 1;
}

HomeRoom::~HomeRoom() {

}

int HomeRoom::event() {
	if (returned > 0) {
		this->returned--;
		cout << "The Clefairy's used wish to slow down real time for " << metronome << " minutes! Use it Wisely!" << endl;
		return metronome;
	}
	else {
		cout << "The Clefairy's cannot grant another wish! Move Quickly!" << endl;
		return 0;
	}
}