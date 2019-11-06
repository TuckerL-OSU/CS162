/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* HarryPotter.cpp
******************************************************************************/
#include "HarryPotter.hpp"

HarryPotter::HarryPotter() {
	name = "Harry Potter";
	attack = 0;
	defense = 0;
	armor = 0;
	strength_points = 10;
	Hogwarts = 1;
}

HarryPotter::~HarryPotter() {

}

int HarryPotter::attackRoll() {
	Die *roll = new Die(6, 2);

	this->attack = roll->roll();

	delete roll;

	return this->attack;
}

void HarryPotter::defenseRoll(int attack) {
	int dmg = attack;
	Die *roll = new Die(6, 2);

	this->defense = roll->roll();

	dmg = attack - defense - armor;
	dmg = dmg <= 0 ? 0 : dmg;

	this->setStrength_Points(this->getStrength_Points() - dmg);

	if (this->getStrength_Points() <= 0 && Hogwarts > 0) {
		setStrength_Points(20);
		Hogwarts -= 1;
	}
	delete roll;
}

void HarryPotter::recoveryRoll() {
	int maxStr_Pts = 0;

	Hogwarts == 1 ? maxStr_Pts = 10 : maxStr_Pts = 20;

	if (this->getStrength_Points() < maxStr_Pts) {
		// rolls a die based on the size of the difference in the health pool
		Die *roll = new Die(maxStr_Pts - this->getStrength_Points(), 1);
		this->setStrength_Points(this->getStrength_Points() + roll->roll());
		delete roll;
	}
}