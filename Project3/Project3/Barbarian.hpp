#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"

class Barbarian : public Character {
public:
	Barbarian();
	Barbarian(int, int);
	~Barbarian();

	int attackRoll();

	int defenseRoll();

	//void setName(string);

};

#endif // !BARBARIAN_HPP

