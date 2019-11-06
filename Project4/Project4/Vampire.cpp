/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* Vampire.cpp
******************************************************************************/
#include "Vampire.hpp"

Vampire::Vampire() {
	name = "Vampire";
	attack = 0;
	defense = 0;
	armor = 1;
	strength_points = 18;
}

Vampire::Vampire(int att, int def) : Character("Vampire", att, def, 1, 18) {
	this->attack = att;
	this->defense = def;
}

Vampire::~Vampire() {

}

int Vampire::attackRoll() {
	Die *roll = new Die(12, 1);

	this->attack = roll->roll();

	delete roll;

	return this->attack;
}

void Vampire::defenseRoll(int attack) {
	charm = RNG(0, 10);
	if (charm < 6) {
		attack = 0;
	}
	else {
		int dmg = attack;
		Die *roll = new Die(6, 1);

		this->defense = roll->roll();

		dmg = attack - defense - armor;
		dmg = dmg <= 0 ? 0 : dmg;

		this->setStrength_Points(this->getStrength_Points() - dmg);
		delete roll;
	}
}

void Vampire::recoveryRoll() {
	int maxStr_Pts = 18;

	if (this->getStrength_Points() < maxStr_Pts) {
		// rolls a die based on the size of the difference in the health pool
		Die *roll = new Die(maxStr_Pts - this->getStrength_Points(), 1);
		this->setStrength_Points(this->getStrength_Points() + roll->roll());
		delete roll;
	}
}