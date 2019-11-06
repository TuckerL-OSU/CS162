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

int Barbarian::defenseRoll() {
	Die *roll = new Die(6, 2);
	this->defense = roll->roll();

	delete roll;

	return this->defense;
}

//void Barbarian::setName(string name) {
//	this->name = name;
//}
//string Barbarian::getName() {
//	return name;
//}