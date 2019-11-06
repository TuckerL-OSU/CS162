/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 3: War Dice
* Die.cpp
******************************************************************************/
#include "Die.hpp"
#include <iostream>

using namespace std;
Die::Die() {
	this->N = 6;
}

Die::Die(int N) {
	this->N = N;
	srand(time(NULL));
}

Die::~Die() {
	this->N = 0;

}

int Die::roll() {
	return rand() % (N) + 1;
}