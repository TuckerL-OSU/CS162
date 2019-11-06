/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Cave.hpp
******************************************************************************/
#ifndef Cave_hpp
#define Cave_hpp
#include "Space.hpp"

class Cave : public Space {
private:
	int item;

public:
	Cave(int, int);
	Cave();
	~Cave();

	int itemFound();
};

#endif // !Cave_hpp
