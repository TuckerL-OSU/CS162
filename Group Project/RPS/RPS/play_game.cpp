/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the entry point for the program
***************************************/
#include "RPSGame.hpp"

int main() {
	// Seed srand to make rand generate random numbers
	srand(time(NULL));

	int choice = 0;
	RPSGame *game;

	cout << "1. Play Rock, Paper, Scissors" << endl;
	cout << "2. Quit" << endl;
	choice = getValidInteger("Which would you like to do? ", 1, 2);

	switch (choice) {
	case 1:
		game = new RPSGame();
		delete game;
		break;
	default:
		break;
	}

return 0;
}
