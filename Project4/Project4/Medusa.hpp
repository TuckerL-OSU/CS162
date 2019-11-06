/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
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

	void recoveryRoll();
};


#endif // !MEDUSA_HPP

