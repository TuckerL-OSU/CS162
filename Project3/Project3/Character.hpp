#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Support.hpp"
#include "Die.hpp"

class Character {
protected:
	string name;
	int attack;
	int defense;
	int armor;
	int strength_points;

public:
	Character();
	Character(string, int, int, int, int);
	~Character();

	void setName(string name);
	virtual string getName();

	virtual int attackRoll() = 0;

	virtual int defenseRoll() = 0;

	void setArmor(int);
	virtual int getArmor();

	void setStrength_Points(int);
	virtual int getStrength_Points();

	static void battle(Character*, Character*);
};

#endif // !CHARACTER_HPP