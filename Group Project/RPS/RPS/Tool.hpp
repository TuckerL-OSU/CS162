/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the class declaration of the Tool class
 * This class is the base class for the Rock, Paper, and
 * Scissors classes
***************************************/
#ifndef TOOL_HPP
#define TOOL_HPP

enum States {
	WIN = 'w',
	LOSS = 'l',
	DRAW = 'd'
};

class Tool {
protected:
	int strength;
	char type;

public:
	Tool();
	Tool(char, int);
	~Tool();

	void setStrength(int);
	int getStrength();

	void setType(char);
	char getType();

	States compareTool(int, int);
	virtual States fight(Tool*);
};

#endif // !TOOL_HPP