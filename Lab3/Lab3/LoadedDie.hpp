/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 3: War Dice
* LoadedDie.hpp
******************************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

class LoadedDie : public Die {
private:
	int load();
protected:

public:
	LoadedDie(int N);
	int roll();
};

#endif