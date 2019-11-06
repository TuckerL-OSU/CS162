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

//void Character::battle(Character *char1, Character *char2) {
//	// tracks who is attacking
//	bool turn = true;
//	int dmg = 0;
//	int def = 0;
//	int att = 0;
//	int arm = 0;
//
//	// randomly chooses 0 or 1 to go first
//	turn = rand() % 2;
//
//	while (!(char1->getStrength_Points() <= 0) && !(char2->getStrength_Points() <= 0)) {
//		//dmg = dmg <= 0 ? 0 : dmg;		
//		if (turn) {
//			cout << char1->getName() << " attacks with dice roll of: ";
//			att = char1->attackRoll();
//			cout << ".\n" << char1->getName() << " has an attack of: " << att << endl;
//			cout << char2->getName() << " defends with dice roll of: ";
//			def = char2->defenseRoll();
//			cout << ".\n" << char2->getName() << " has a defense of: " << def << endl;
//			arm = char2->getArmor();
//			cout << char2->getName() << " has an armor rating of: " << arm << endl;
//			dmg = att - def - arm;
//			cout << char1->getName() << " actually did " << dmg << " damage to " << char2->getName();
//			cout << ".\n" << char2->getName() << " had " << char2->getStrength_Points() << " strength points, and now has ";
//			char2->setStrength_Points(char2->getStrength_Points() - dmg);
//			cout << char2->getStrength_Points() << " strength points left." << endl;
//		}
//
//	}
//}

void Character::battle(Character *attacker, Character *defender) {
	// tracks who is attacking
	bool turn = true;
	int dmg = 0;
	int def = 0;
	int att = 0;
	int arm = 0;


	if (!(attacker->getStrength_Points() <= 0) && !(defender->getStrength_Points() <= 0)) {
		cout << attacker->getName() << " is attacking " << defender->getName() << endl;
		cout << attacker->getName() << " attacks with dice roll of: ";
		att = attacker->attackRoll();
		cout << "\n" << attacker->getName() << " has an attack of: " << att << endl;
		cout << defender->getName() << " defends with dice roll of: ";
		def = defender->defenseRoll();
		cout << "\n" << defender->getName() << " has a defense of: " << def << endl;
		arm = defender->getArmor();
		cout << defender->getName() << " has an armor rating of: " << arm << endl;
		dmg = att - def - arm;
		dmg = dmg <= 0 ? 0 : dmg;		
		cout << attacker->getName() << " dealt " << dmg << " damage to " << defender->getName();
		cout << ".\n" << defender->getName() << " had " << defender->getStrength_Points() << " strength points, and now has ";
		defender->setStrength_Points(defender->getStrength_Points() - dmg);
		cout << defender->getStrength_Points() << " strength points left." << endl << endl;


		Character::battle(defender, attacker);
	}
	else {
		cout << "someone deaded" << endl;
		return;
	}
}