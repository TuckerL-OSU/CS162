/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
* Game.hpp
******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"

class Game {
public:
	Game();
	~Game();

	Character *p1;
	Character *p2;

	void chooseChar();
	void createChar(int, int);
	void play();

};

#endif // !GAME_HPP