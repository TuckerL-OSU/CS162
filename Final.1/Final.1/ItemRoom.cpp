/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* ItemRoom.cpp
******************************************************************************/
#include "ItemRoom.hpp"

ItemRoom::ItemRoom() {
	this->state = MOONSTONE;
	this->moonStone = 1;
}

ItemRoom::~ItemRoom() {

}

int ItemRoom::event() {
	if (state = MOONSTONE) {
		cout << "This Room is full of sparkly Rocks!" << endl;
		cout << "You are positive these are MoonStones!" << endl;
		return moonStone;
	}
	else {
		cout << "You already found everything in this room!" << endl;
		return 0;
	}
}