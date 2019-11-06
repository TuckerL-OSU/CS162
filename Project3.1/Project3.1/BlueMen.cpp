/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
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

	cout << this->getName() << " attacks with dice roll of: ";
	this->attack = roll->roll();
	cout << "\n" << this->getName() << " has an attack of: " << attack << endl;

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

	cout << this->getName() << " defends with dice roll of: ";
	this->defense = roll->roll();
	cout << "\n" << this->getName() << " has a defense of: " << defense << endl;
	cout << this->getName() << " has an armor rating of: " << armor << endl;

	dmg = attack - defense - armor;
	dmg = dmg <= 0 ? 0 : dmg;

	cout << this->getName() << " took " << dmg << " damage this round." << endl;
	cout << this->getName() << " went from " << this->getStrength_Points();
	this->setStrength_Points(this->getStrength_Points() - dmg);
	cout << " to " << this->getStrength_Points() << " strength points." << endl << endl;
	delete roll;

}