/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the class declaration of the Scissors class
***************************************/
#ifndef SCISSORS_HPP
#define SCISSORS_HPP
#include "Tool.hpp"

class Scissors : public Tool {
public:
	Scissors();
	Scissors(char, int);
	~Scissors();

	States fight(Tool*);
};

#endif // !SCISSORS_HPP