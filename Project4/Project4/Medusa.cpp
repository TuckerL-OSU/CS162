/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* Medusa.cpp
******************************************************************************/
#include "Medusa.hpp"

Medusa::Medusa() {
	name = "Medusa";
	attack = 0;
	defense = 0;
	armor = 3;
	strength_points = 8;
}

Medusa::~Medusa() {

}

int Medusa::attackRoll() {
	Die *roll = new Die(6, 2);

	this->attack = roll->roll();
	if (attack == 12) {
		this->attack = 1000;
	}

	delete roll;

	return this->attack;

}

void Medusa::defenseRoll(int attack) {
	int dmg = attack;
	Die *roll = new Die(6, 1);

	this->defense = roll->roll();

	dmg = attack - defense - armor;
	dmg = dmg <= 0 ? 0 : dmg;

	this->setStrength_Points(this->getStrength_Points() - dmg);
	delete roll;
}

void Medusa::recoveryRoll() {
	int maxStr_Pts = 8;

	if (this->getStrength_Points() < maxStr_Pts) {
		// rolls a die based on the size of the difference in the health pool
		Die *roll = new Die(maxStr_Pts - this->getStrength_Points(), 1);
		this->setStrength_Points(this->getStrength_Points() + roll->roll());
		delete roll;
	}
}