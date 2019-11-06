#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <locale>
#include <limits.h>
#include "Die.hpp"
#include "LoadedDie.hpp"

using std::cout;
/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 3: War Dice
* Game.hpp
******************************************************************************/
using std::cin;
using std::endl;
using std::string;
using std::tolower;
using std::getline;

class Game {
private:
	int numOfRounds;
	int p1CurrentRoll;
	int p2CurrentRoll;
	string p1DieType;
	string p2DieType;
	Die *p1;
	Die *p2;
	void buildGame();
	void play();
	void printGame(int, int, int, int);

public:
	Game();
	~Game();
	static int getValidIntegerInput(string, int, int);

};
#endif