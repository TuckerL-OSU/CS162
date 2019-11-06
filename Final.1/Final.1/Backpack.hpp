/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Backpack.hpp
******************************************************************************/
#ifndef Backpack_hpp
#define Backpack_hpp
#include "Support.hpp"
#include <deque>

using std::deque;

class Backpack {
private:
	int capacity;
	deque<string> inventory;

	bool invFull();

public:
	Backpack();
	~Backpack();

	void addToInv(string);
	void removeFromInv();
	void printInv();
	int getSize();
	int getCapacity();
};

#endif // !Backpack_hpp
