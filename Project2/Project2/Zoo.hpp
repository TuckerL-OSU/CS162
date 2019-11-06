/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Zoo.hpp
******************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::copy;

class Zoo {
private:
	Animal *tigers;
	Animal *penguins;
	Animal *turtles;
	Animal *animals;
	int animalCapacity;
	int numTigers;
	int numPenguins;
	int numTurtles;
	int numSpecies;
	double income;

	void ageAnimals();
	void sick(Animal*, int&);
	bool baby(Animal*, Animal, int&);
	int RNG(int, int);
	void resizeArray(Animal*, int);

public:
	Zoo();
	~Zoo();
	void fillZoo(Animal*, Animal, int, int);
	double feedCosts();
	double dailyEvent();
	double calcIncome();
	void buildZoo();
	void buyAnimal();
	void begOfDay();
	bool endOfDay();

	double bank;
	int numOfCurrentAnimals;
	int dayOfOp;
};

#endif // !ZOO_HPP
