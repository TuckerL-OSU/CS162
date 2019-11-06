/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Tiger.hpp
******************************************************************************/
#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

class Tiger : public Animal {
private:

protected:

public:
	Tiger();
	~Tiger();
	void setBaseFoodCost(double);
	double getBaseFoodCost();
	void setAge(int);
	int getAge();
};

#endif // !TIGER_HPP