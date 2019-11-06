/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* RocketRoom.cpp
******************************************************************************/
#include "RocketRoom.hpp"

RocketRoom::RocketRoom() {
	this->state = ROCKET;
}

RocketRoom::~RocketRoom() {

}

int RocketRoom::event() {
	return 1;
}