#include "Rock.hpp"

Rock::Rock() {
	strength = 1;
	type = 'r';
}

Rock::~Rock() {

}

void Rock::setStrength(int s) {
	this->strength = s;
}
int Rock::getStrength() {
	return strength;
}

void Rock::setType(char t) {
	this->type = t;
}
char Rock::getType() {
	return type;
}

// c is the tool for the computer
States Rock::fight(Tool* c) {
	switch (c->getType()) {
	case 's': // rock beats scissor
		return compareTool((this->getStrength() * 2), c->getStrength());
	case 'p': // rock loses to paper
		return compareTool((this->getStrength() / 2), c->getStrength());
	case 'r': // rock vs rock
		return DRAW;
	default:
		break;
	}
}