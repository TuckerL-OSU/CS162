/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Game.hpp
******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <locale>
#include <limits.h>
#include <time.h>
#include "Zoo.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::tolower;
using std::getline;

class Game {
private:
	int numOfRounds;
	void play();
	Zoo *zoo;

public:
	Game();
	~Game();

};
#endif