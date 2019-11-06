/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the class declaration of the RPSGame class
***************************************/
#ifndef RPSGAME_HPP
#define RPSGAME_HPP
#include "Tool.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"
#include "Support.hpp"
#include <cstdlib>
#include <ctime>

class RPSGame {
private:
	Tool* player;
	Tool* computer;
	int human_wins;
	int computer_wins;
	int ties;

	int playerRockStrength;
	int playerPaperStrength;
	int playerScissorsStrength;

	int computerRockStrength;
	int computerPaperStrength;
	int computerScissorsStrength;

	bool defaultGame;

public:
	RPSGame();
	~RPSGame();
	void play();
	void start();
	void setToolStrength();
	Tool* generateTool(char, int);
};

#endif // !RPSGAME_HPP
