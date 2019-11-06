/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Space.cpp
******************************************************************************/
#include "Space.hpp"

Space::Space() {
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;
}

Space::~Space() {

}

void Space::moveNorth() {
	if (current->north == nullptr) {
		location->north = new Room(current->y--, current->x);
		location->north->south = location;
	}
	location->north->south = location;
	location = location->north;
	location->state = CURRENT;
	location->south->state = (SpaceState)NORTH;
}

Space* Space::move(Direction direction) {
	switch (direction) {
	case NORTH:
		return north;
	case SOUTH:
		return south;
	case EAST:
		return east;
	case WEST:
		return west;
	default:
		return nullptr;
	}
}

void Space::setNorth(Space *north) {
	this->north = north;
}
Space* Space::getNorth() {
	return north;
}

void Space::setSouth(Space *south) {
	this->south = south;
}
Space* Space::getSouth() {
	return south;
}

void Space::setEast(Space *east) {
	this->east = east;
}
Space* Space::getEast() {
	return east;
}

void Space::setWest(Space *west) {
	this->west = west;
}
Space* Space::getWest() {
	return west;
}