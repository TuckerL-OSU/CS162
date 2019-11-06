/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the class declaration of the Paper class
***************************************/
#ifndef PAPER_HPP
#define PAPER_HPP
#include "Tool.hpp"

class Paper : public Tool {
public:
	Paper();
	Paper(char, int);
	~Paper();

	States fight(Tool*);
};

#endif // !PAPER_HPP