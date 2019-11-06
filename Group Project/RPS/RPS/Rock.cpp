/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the class definition/implementation of the Rock class
***************************************/
#include "Rock.hpp"
/**
 * Rock default constructor
 **/
Rock::Rock() {
	setStrength(1);
	setType('r');
}

/**
 * Rock constructor with strength parameter
 * @param int s
 * -	Strength for the item
 **/
Rock::Rock(char t, int s) : Tool(t, s) {
	setStrength(s);
	setType(t);
}

/**
 * Rock Destructor
 **/
Rock::~Rock() {}

/**
 * Method for implementing a round of a Rock,
 * Paper, Scissors game. Method pits the Rock
 * tool against other tools. Each tool has a
 * disadvantage or advantage to the scissor tool
 * @param Tool* c
 * -	A pointer to a Tool
 * @return States
 * -	The result of the match
 **/
States Rock::fight(Tool* c) {
	switch (c->getType()) {
	case 's': // rock has an advantage to scissor
		return compareTool((this->getStrength() * 2), c->getStrength() / 2);
		break;
	case 'p': // rock has a disadvantage to paper
		return compareTool((this->getStrength() / 2), c->getStrength() * 2);
		break;
	case 'r': // rock vs rock
		return compareTool((this->getStrength()), c->getStrength());
		break;
	default:
		return DRAW;
	}
}
