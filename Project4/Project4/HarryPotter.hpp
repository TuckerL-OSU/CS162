/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* HarryPotter.hpp
******************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Character.hpp"

class HarryPotter : public Character {
private:
	int Hogwarts;

public:
	HarryPotter();
	~HarryPotter();

	int attackRoll();

	void defenseRoll(int);

	void recoveryRoll();
};


#endif // !HARRYPOTTER_HPP

