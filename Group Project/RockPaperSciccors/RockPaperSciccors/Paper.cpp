#include "Paper.hpp"

Paper::Paper() {
	strength = 1;
	type = 'p';
}

Paper::~Paper() {

}

void Paper::setStrength(int s) {
	this->strength = s;
}
int Paper::getStrength() {
	return strength;
}

void Paper::setType(char t) {
	this->type = t;
}
char Paper::getType() {
	return type;
}

// c is the tool for the computer
States Paper::fight(Tool *c) {
	switch (c->getType()) {
	case 'r': // paper beats rock
		return compareTool((this->getStrength() * 2), c->getStrength());
		break;
	case 's': // paper loses to scissors
		return compareTool((this->getStrength() / 2), c->getStrength());
		break;
	case 'p': // paper vs paper
		return DRAW;
	default:
		break;
	}

	return DRAW;
}