/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
* Vampire.hpp
******************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"

class Vampire : public Character {
private:
	int charm;

public:
	Vampire();
	Vampire(int, int);
	~Vampire();

	int attackRoll();

	void defenseRoll(int);

};

#endif // !VAMPIRE_HPP

