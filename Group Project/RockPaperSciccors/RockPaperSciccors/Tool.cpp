#include "Tool.hpp"

Tool::Tool() {
	strength = 1;
}

Tool::~Tool() {

}

void Tool::setStrength(int s) {
	this->strength = s;
}
int Tool::getStrength() {
	return strength;
}

void Tool::setType(char t) {
	this->type = t;
}
char Tool::getType() {
	return type;
}

States Tool::compareTool(int a, int b) {
	if (a > b) {
		return WIN;
	}
	else if (a < b) {
		return LOSS;
	}
	else {
		return DRAW;
	}
}
