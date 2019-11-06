/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
* Die.hpp
******************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP
#include "Support.hpp"


class Die {
protected:
	int sides;
	int rolls;

public:
	Die();
	Die(int, int);
	~Die();
	virtual int roll();

	void setSides(int);
	virtual int getSides();
	
	void setRolls(int);
	virtual int getRolls();
};

#endif
