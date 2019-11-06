/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Penguin.hpp
******************************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal {
private:

protected:

public:
	Penguin();
	~Penguin();
	void setBaseFoodCost(double);
	double getBaseFoodCost();
	void setAge(int);
	int getAge();
};


#endif // !PENGUIN_HPP