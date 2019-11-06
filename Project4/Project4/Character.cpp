/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* Character.cpp
******************************************************************************/
#include "Character.hpp"

Character::Character() {
	this->name = "Nobody";
	this->attack = 0;
	this->defense = 0;
	this->armor = 0;
	this->strength_points = 0;
}

Character::Character(string n, int att, int def, int arm, int str_pts) {
	this->name = n;
	this->attack = att;
	this->defense = def;
	this->armor = arm;
	this->strength_points = str_pts;
}

Character::~Character() {
	
}

void Character::setName(string n) {
	this->name = n;
}
string Character::getName() {
	return name;
}

void Character::setArmor(int arm) {
	this->armor = arm;
}
int Character::getArmor() {
	return armor;
}

void Character::setStrength_Points(int str_pts) {
	this->strength_points = str_pts;
}
int Character::getStrength_Points() {
	return strength_points;
}

void Character::combat(Character *attacker, Character *defender) {
	int att = 0;
	static int round = 0;

	if (attacker == nullptr)
		cout << "attacker is null" << endl;

	if (defender == nullptr)
		cout << "defendeer is null" << endl;

	if (!(attacker->getStrength_Points() <= 0) && !(defender->getStrength_Points() <= 0)) {
		if (round == 0) {
			cout << attacker->getName() << " vs " << defender->getName() << endl;
		}
		att = attacker->attackRoll();
		defender->defenseRoll(att);
		round++;

		Character::combat(defender, attacker);
	}
	else if (attacker->getStrength_Points() <= 0) {
		cout << defender->getName() << " has triumphed over " << attacker->getName() << endl << endl;
		round = 0;
	}
	else if (defender->getStrength_Points() <= 0) {
		cout << attacker->getName() << " has triumphed over " << defender->getName() << endl << endl;
		round = 0;
	}
	else
		return;
}
