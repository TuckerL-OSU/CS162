/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the class definition/implementation of the Tool class
 * This class is the base class for the Rock, Paper, and
 * Scissors classes
***************************************/
#include "Tool.hpp"

/**
 * Tool default constructor
 **/
Tool::Tool() {
	strength = 1;
}

/**
 * Tool constructor with strength parameter
 * @param int s
 * -	Strength for the item
 **/
Tool::Tool(char t, int s) {
	type = t;
	strength = s;
}

/**
 * Tool Destructor
 **/
Tool::~Tool() {}

/**
 * Setter for the strength data member
 * @param int s
 * -	The strength for the tool
 * @param void
 **/
void Tool::setStrength(int s) {
	this->strength = s;
}

/**
 * Getter for the strength data member
 * @param void
 * @return int strength
 * -	The strength for the tool
 **/
int Tool::getStrength() {
	return strength;
}

/**
 * Setter for the type data member
 * @param char t
 * -	The type of the tool
 @return void
 **/
void Tool::setType(char t) {
	this->type = t;
}

/**
 * Getter for the type data member
 * @param void
 * @return char type
 * -	The type of the tool
 **/
char Tool::getType() {
	return type;
}

/**
 * Method helps to compare the strangth of
 * two tools.
 * @param int a
 * -	Strength for the first tool
 * @param int b
 * -	Strength for the second tool
 * @param States
 * -	Whether Tool a won or not
 **/
States Tool::compareTool(int a, int b) {
	if (a > b) {
		return WIN;
	} else if (a < b) {
		return LOSS;
	} else {
		return DRAW;
	}
}

/**
 * Method for having two tools fight each
 * other. Method is virtual so child classes
 * can implement their own fight methods.
 * @param Tool* t
 * -	The tool to fight with
 * @return States
 * -	Result of the match
 **/
States Tool::fight(Tool* t) { return DRAW; }
