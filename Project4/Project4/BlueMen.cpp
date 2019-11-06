/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* BlueMen.cpp
******************************************************************************/
#include "BlueMen.hpp"

BlueMen::BlueMen() {
	name = "Blue Men";
	attack = 0;
	defense = 0;
	armor = 3;
	strength_points = 12;
}

BlueMen::~BlueMen() {

}

int BlueMen::attackRoll() {
	Die *roll = new Die(10, 2);

	this->attack = roll->roll();

	delete roll;

	return this->attack;
}

void BlueMen::defenseRoll(int attack) {
	int dmg = attack;
	int currentStr_Pts = getStrength_Points();
	Die *roll;

	if (currentStr_Pts > 0 && currentStr_Pts <= 4) {
		roll = new Die(6, 1);
	}
	else if (currentStr_Pts >= 5 && currentStr_Pts <= 8) {
		roll = new Die(6, 2);
	}
	else {
		roll = new Die(6, 3);
	}

	this->defense = roll->roll();

	dmg = attack - defense - armor;
	dmg = dmg <= 0 ? 0 : dmg;

	this->setStrength_Points(this->getStrength_Points() - dmg);
	delete roll;
}

void BlueMen::recoveryRoll() {
	int maxStr_Pts = 12;

	if (this->getStrength_Points() < maxStr_Pts) {
		// rolls a die based on the size of the difference in the health pool
		Die *roll = new Die(maxStr_Pts - this->getStrength_Points(), 1);
		this->setStrength_Points(this->getStrength_Points() + roll->roll());
		delete roll;
	}
}