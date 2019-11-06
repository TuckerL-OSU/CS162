/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Turtle.hpp
******************************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle : public Animal {
private:

protected:

public:
	Turtle();
	~Turtle();
	void setBaseFoodCost(double);
	double getBaseFoodCost();
	void setAge(int);
	int getAge();

};


#endif // !TURTLE_HPP
