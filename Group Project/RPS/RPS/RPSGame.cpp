/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the class definition/implementation of the RPSGame class
***************************************/
#include "RPSGame.hpp"

/**
 * RPSGame default Constructor
 **/
RPSGame::RPSGame() {
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
	defaultGame = true;
	start();
}

/**
 * Destructor for the RPSGame
 **/
RPSGame::~RPSGame() {
	if (player) {
		delete player;
	}

	if (computer) {
		delete computer;
	}
}

/**
 * Method for starting the game
 * Prompst the user for the type of game
 * they would like to play
 * @param void
 * @return void
 **/
void RPSGame::start() {
	char input = ' ';
	bool validate = false;

	cout << "\nWelcome to Rock, Paper, Scissors!\n";

	while (!validate) {
		input = getCharInput("Do you want to choose different strengths for the tools? (y-yes, n-no): ");

		switch (input) {
		case 'y':
			//setToolStrength(); // set custom tool strengths
			defaultGame = false; // custom game
			setToolStrength();
			play();
			validate = true;
			break;
		case 'n': // default game
			play();
			validate = true;
			break;
		default:
			break;
		}
	}
}

/**
 * Method for implementing the RPS game
 * Method prompts the user for the type of
 * tool they'd like to use, has the computer
 * pick a tool, has the tool fights, and asks
 * the user if they'd to play again
 * @param void
 * @return void
 **/
void RPSGame::play() {
	char input = ' ';
	int computerChoice = 0;
	States outcome;
	bool validate = false;


	do {
		while (!validate) {
			input = getCharInput("Choose your tool (r-rock, p-paper, s-scissor, e-exit): ");
			if (input == 'r' || input == 'p' || input == 's' || input == 'e') {
				validate = true;
			}
		}

		// breaks the do while to end the game if they chose exit
		if (input == 'e')
			break;

		// Decide which game to play
		if (defaultGame) {
			// Prompt use for their tool
			player = generateTool(input, 1);
			// Computer chooses a tool
			computerChoice = RNG(1, 3);
			// in a default game all the strengths are 1
			switch (computerChoice) {
			case 1: // rock
				computer = generateTool('r', 1);
				break;
			case 2: // paper
				computer = generateTool('p', 1);
				break;
			case 3: // scissors
				computer = generateTool('s', 1);
				break;
			default:
				break;
			}
		}
		else {
			switch (input) {
			case 'r':
				player = generateTool(input, playerRockStrength);
				break;
			case 'p':
				player = generateTool(input, playerPaperStrength);
				break;
			case 's':
				player = generateTool(input, playerScissorsStrength);
				break;
			default:
				break;
			}

			computerChoice = RNG(1, 3);
			switch (computerChoice) {
			case 1:
				computer = generateTool('r', computerRockStrength);
				break;
			case 2: // paper
				computer = generateTool('p', computerPaperStrength);
				break;
			case 3: // scissors
				computer = generateTool('s', computerScissorsStrength);
				break;
			default:
				break;
			}
		}

		if (computer->getType() == 'r') {
			cout << "Computer chose rock." << endl;
		}
		else if (computer->getType() == 'p') {
			cout << "Computer chose paper." << endl;
		}
		else if (computer->getType() == 's') {
			cout << "Computer chose scissors." << endl;
		}

		// Player fights the computer
		outcome = player->fight(computer);

		// The outcome of the match
		switch (outcome) {
		case WIN:
			cout << "You win!!!" << endl;
			human_wins++;
			break;
		case LOSS:
			cout << "Computer wins! :-(" << endl;
			computer_wins++;
			break;
		case DRAW:
			cout << "Tie!" << endl;
			ties++;
			break;
		default:
			break;
		}

		cout << endl;
		cout << "Human wins: " << human_wins << endl;
		cout << "Computer wins: " << computer_wins << endl;
		cout << "Ties: " << ties << endl;
		cout << endl;

		// Free dynamic memory to prevent leaks
		delete computer;
		delete player;

		// Set them to NULL, since it contains the address even though it's freed
		player = NULL;
		computer = NULL;

		//Reset Player Input
		validate = false;

	} while (playAgain()); // Ask the user if they'd like to play again

	cout << "End of program." << endl;
}

/**
 * Method for allocating memory for a tool
 * based on user choice
 * @param char tool
 * -	User's choice
 * @param Tool*
 * -	A pointer to a tool (rock, paper, scissor)
 **/
Tool* RPSGame::generateTool(char tool, int str) {
	switch (tool) {
	case 'r':
		return new Rock(tool, str);
		break;
	case 'p':
		return new Paper(tool, str);
		break;
	case 's':
		return new Scissors(tool, str);
		break;
	default:
		break;
	}

	return NULL;
}

/**
 * Method for prompting the user for the
 * custom strengths of the tools
 * @param void
 * @return void
 **/
void RPSGame::setToolStrength() {
	cout << endl;
	cout << "Please enter the strengths of the Player's tools." << endl;
	playerRockStrength = getValidInteger("Rock: ", INT_MIN, INT_MAX);
	playerPaperStrength = getValidInteger("Paper: ", INT_MIN, INT_MAX);
	playerScissorsStrength = getValidInteger("Scissors: ", INT_MIN, INT_MAX);

	cout << endl;
	cout << "Please enter the strengths of the Computer's tools." << endl;
	computerRockStrength = getValidInteger("Rock: ", INT_MIN, INT_MAX);
	computerPaperStrength = getValidInteger("Paper: ", INT_MIN, INT_MAX);
	computerScissorsStrength = getValidInteger("Scissors: ", INT_MIN, INT_MAX);
}
