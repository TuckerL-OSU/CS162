/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
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

	cout << this->getName() << " attacks with dice roll of: ";
	this->attack = roll->roll();
	//this->attack = 12;
	if (attack == 12) {
		cout << "\n" << this->getName() << " used Glare!" << endl;
		this->attack = 1000;
	}
	else {
		cout << "\n" << this->getName() << " has an attack of: " << attack << endl;
	}

	delete roll;

	return this->attack;

}

void Medusa::defenseRoll(int attack) {
	int dmg = attack;
	Die *roll = new Die(6, 1);

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