/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
* Medusa.hpp
******************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"

class Medusa : public Character {
private:
	int glare;

public:
	Medusa();
	Medusa(int, int);
	~Medusa();

	int attackRoll();

	void defenseRoll(int);

};


#endif // !MEDUSA_HPP

