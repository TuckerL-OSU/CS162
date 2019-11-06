/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Cave.cpp
******************************************************************************/
#include "Cave.hpp"

Cave::Cave(int Y, int X) {
	location = new Room(Y, X);
}