/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
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

	cout << this->getName() << " attacks with dice roll of: ";
	this->attack = roll->roll();
	cout << "\n" << this->getName() << " has an attack of: " << attack << endl;

	delete roll;

	return this->attack;
}

void HarryPotter::defenseRoll(int attack) {
	int dmg = attack;
	Die *roll = new Die(6, 2);
	//Die *roll = new Die(6, 1);

	cout << this->getName() << " defends with dice roll of: ";
	this->defense = roll->roll();
	cout << "\n" << this->getName() << " has a defense of: " << defense << endl;
	cout << this->getName() << " has an armor rating of: " << armor << endl;

	dmg = attack - defense - armor;
	dmg = dmg <= 0 ? 0 : dmg;

	cout << this->getName() << " took " << dmg << " damage this round." << endl;
	cout << this->getName() << " went from " << this->getStrength_Points();
	this->setStrength_Points(this->getStrength_Points() - dmg);
	cout << " to " << this->getStrength_Points() << " strength points." << endl;

	if (this->getStrength_Points() <= 0 && Hogwarts > 0) {
		cout << this->getName() << " isn't dead yet! In fact they're not done fighting!" << endl;
		setStrength_Points(20);
		cout << this->getName() << " has come back with " << getStrength_Points() << " strength points." << endl;
		Hogwarts -= 1;
	}

	cout << endl;
	delete roll;
}