/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 3: War Dice
* LoadedDie.cpp
******************************************************************************/
#include "LoadedDie.hpp"

LoadedDie::LoadedDie(int N) : Die(N) {
	this->N = N;
}

int LoadedDie::load() {
	// sort of average of 3 rolls, int truncation does not matter here
	int load = ((rand() % N + 1) + (rand() % N + 1) + (rand() % N + 1)) / 2.5;
	if (load == N) {
		return load;
	}
	else if (load >= N) {
		return N;
	}
	else {
		return load;
	}
}

int LoadedDie::roll() {
	return load();
}

