/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Animal.hpp
******************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

using std::string;

class Animal {
private:

protected:
	int age;
	double cost;
	int numberOfBabies;
	double baseFoodCost;
	double payoff;

public:
	Animal();
	~Animal();
	void setAge(int);
	void setCost(double);
	void setNumberOfBabies(int);
	void setBaseFoodCost(double);
	void setPayoff(double);

	virtual bool isAdult();
	virtual int getAge();
	virtual double getCost();
	virtual int getNumberOfBabies();
	virtual double getBaseFoodCost();
	virtual double getPayoff();
};

#endif // !ANIMAL_HPP
