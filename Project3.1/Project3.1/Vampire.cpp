/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
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

	cout << this->getName() << " attacks with dice roll of: ";
	this->attack = roll->roll();
	cout << "\n" << this->getName() << " has an attack of: " << attack << endl;

	delete roll;

	return this->attack;
}

void Vampire::defenseRoll(int attack) {
	charm = (rand() % 10) + 0;
	if (charm < 6) {
		attack = 0;
		cout << "BUT, Vampires Charm was activated! " << this->getName();
		cout << " took no damage this round!" << endl;
		cout << this->getName() << " has " << this->getStrength_Points();
		cout << " strength points" << endl << endl;
	}
	else {
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
}