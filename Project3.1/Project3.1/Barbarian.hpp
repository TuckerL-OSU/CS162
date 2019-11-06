/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
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

	//void setName(string);

};

#endif // !BARBARIAN_HPP

