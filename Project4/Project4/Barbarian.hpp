/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* Barbarian.hpp
******************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"

class Barbarian : public Character {
public:
	Barbarian();
	Barbarian(int, int);
	~Barbarian();

	int attackRoll();

	void defenseRoll(int);

	void recoveryRoll();
};

#endif // !BARBARIAN_HPP

