/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* Barbarian.cpp
******************************************************************************/
#include "Barbarian.hpp"

Barbarian::Barbarian() {
	name = "Barbarian";
	attack = 0;
	defense = 0;
	armor = 0;
	strength_points = 12;
}

Barbarian::Barbarian(int att, int def) : Character("Barbarian", att, def, 0, 12) {
	this->attack = att;
	this->defense = def;
}

Barbarian::~Barbarian() {

}

int Barbarian::attackRoll() {
	Die *roll = new Die(6, 2);

	this->attack = roll->roll();

	delete roll;

	return this->attack;
}

void Barbarian::defenseRoll(int attack) {
	int dmg = attack;
	Die *roll = new Die(6, 2);

	this->defense = roll->roll();

	dmg = attack - defense - armor;
	dmg = dmg <= 0 ? 0 : dmg;

	this->setStrength_Points(this->getStrength_Points() - dmg);
	delete roll;
}

void Barbarian::recoveryRoll() {
	int maxStr_Pts = 12;

	if (this->getStrength_Points() < maxStr_Pts) {
		// rolls a die based on the size of the difference in the health pool
		Die *roll = new Die(maxStr_Pts - this->getStrength_Points(), 1);
		this->setStrength_Points(this->getStrength_Points() + roll->roll());
		delete roll;
	}
}