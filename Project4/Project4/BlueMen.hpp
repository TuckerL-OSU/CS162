/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* BlueMen.hpp
******************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"

class BlueMen : public Character {
public:
	BlueMen();
	~BlueMen();

	int attackRoll();

	void defenseRoll(int);

	void recoveryRoll();
};

#endif // !BLUEMEN_HPP

