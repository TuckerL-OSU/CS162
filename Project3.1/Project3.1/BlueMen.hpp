/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
* BlueMen.hpp
******************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"

class BlueMen : public Character {
private:
	int mob;

public:
	BlueMen();
	BlueMen(int, int);
	~BlueMen();

	int attackRoll();

	void defenseRoll(int);
};

#endif // !BLUEMEN_HPP

