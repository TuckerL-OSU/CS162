#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"

class Vampire : public Character {
private:
	int charm;

public:
	Vampire();
	Vampire(int, int);
	~Vampire();

	int attackRoll();

	int defenseRoll();

};

#endif // !VAMPIRE_HPP

