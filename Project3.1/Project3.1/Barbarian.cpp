/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
* Barbarian.cpp
******************************************************************************/
#include "Barbarian.hpp"

Barbarian::Barbarian() {
	name = "Barbarian";
	attack = 0;
	defense = 0;
	armor = 0;
	strength_points = 12;
}

Barbarian::Barbarian(int att, int def) : Character("Barbarian", att, def, 0, 12){
	this->attack = att;
	this->defense = def;
}

Barbarian::~Barbarian() {

}

int Barbarian::attackRoll() {
	Die *roll = new Die(6, 2);

	cout << this->getName() << " attacks with dice roll of: ";
	this->attack = roll->roll();
	cout << "\n" << this->getName() << " has an attack of: " << attack << endl;

	delete roll;

	return this->attack;
}

void Barbarian::defenseRoll(int attack) {
	int dmg = attack;
	Die *roll = new Die(6, 2);

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

	//return dmg;
}

//void Barbarian::setName(string name) {
//	this->name = name;
//}
//string Barbarian::getName() {
//	return name;
//}