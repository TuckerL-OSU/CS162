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

int Vampire::defenseRoll() {
	charm = (rand() % 10) + 0;
	if (charm < 6) {
		cout << "Vampires Charm was activated!" << endl;
	}
	else {
		Die *roll = new Die(6, 1);
		this->defense = roll->roll();

		delete roll;

		return this->defense;
	}
}