/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the class definition/implementation of the Paper class
***************************************/
#include "Paper.hpp"

/**
 * Paper default constructor
 **/
Paper::Paper() {
	setStrength(1);
	setType('p');
}

/**
 * Paper constructor with strength parameter
 * @param int s
 * -	Strength for the item
 **/
Paper::Paper(char t, int s) : Tool(t, s) {
	setStrength(s);
	setType(t);
}

/**
 * Paper Destructor
 **/
Paper::~Paper() {}

/**
 * Method for implementing a round of a Rock,
 * Paper, Scissors game. Method pits the Paper
 * tool against other tools. Each tool has a
 * disadvantage or advantage to the scissor tool
 * @param Tool* c
 * -	A pointer to a Tool
 * @return States
 * -	The result of the match
 **/
States Paper::fight(Tool *c) {
	switch (c->getType()) {
	case 'r': // paper has an advantage to rock
		return compareTool((this->getStrength() * 2), c->getStrength() / 2);
		break;
	case 's': // paper has a disadvantage to scissors
		return compareTool((this->getStrength() / 2), c->getStrength() * 2);
		break;
	case 'p': // paper vs paper
		return compareTool((this->getStrength()), c->getStrength());
		break;
	default:
		return DRAW;
	}
}
