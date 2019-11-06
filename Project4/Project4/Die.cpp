/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* Die.cpp
******************************************************************************/
#include "Die.hpp"

Die::Die() {
	sides = 6;
	rolls = 0;
}

Die::Die(int s, int r) {
	 this->sides = s;
	 this->rolls = r;
}

Die::~Die() {

}

int Die::roll() {
	//int currentRoll = 0;
	//if (this->rolls < 1) {
	//	return 0;
	//}
	//for (int i = 0; i < this->rolls; i++) {
	//	this->rolls--;
	//	currentRoll = rand() % this->sides + 1;
	//	if (i + 1 == this->rolls) {
	//		cout << currentRoll;
	//	}
	//	else {
	//		cout << currentRoll << " ";
	//	}
	//	return currentRoll + roll();
	//}
	int value = 0;
	int roll;
	for (int i = 0; i < this->rolls; i++) {
		roll = (rand() % this->sides) + 1;
		//cout << roll << " "; // << (i < this->rolls - 1) ? " " : "";
		value += roll;
	}
	
	return value;
}

void Die::setSides(int s) {
	this->sides = s;
}
int Die::getSides() {
	return sides;
}

void Die::setRolls(int r) {
	this->rolls = r;
}
int Die::getRolls() {
	return rolls;
}


