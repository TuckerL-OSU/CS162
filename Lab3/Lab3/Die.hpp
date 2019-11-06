/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 3: War Dice
* Die.hpp
******************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP
#include <time.h>
#include <iostream>

class Die {
private:

protected:
	int N;

public:
	Die();
	Die(int);
	~Die();
	virtual int roll();
};

#endif
