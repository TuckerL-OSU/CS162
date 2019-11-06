/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
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
};


#endif // !HARRYPOTTER_HPP

