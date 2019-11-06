#include "Scissors.hpp"

Scissors::Scissors() {
	strength = 1;
	type = 's';
}

Scissors::~Scissors() {

}

void Scissors::setStrength(int s) {
	this->strength = s;
}
int Scissors::getStrength() {
	return strength;
}

void Scissors::setType(char t) {
	this->type = t;
}
char Scissors::getType() {
	return type;
}

// c is the tool for the computer
States Scissors::fight(Tool *c) {
	switch (c->getType()) {
	case 'p': // scissors beats paper
		return compareTool((this->getStrength() * 2), c->getStrength());
	case 'r': // scissors loses to rock
		return compareTool((this->getStrength() / 2), c->getStrength());
	case 's': // scissors vs scissors
		return DRAW;
	default:
		break;
	}

	return DRAW;
}