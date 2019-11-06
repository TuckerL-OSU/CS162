/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 3: War Dice
* Game.cpp
******************************************************************************/
#include "Game.hpp"

// constructor
Game::Game() {
	cout << "Setting up the game..." << endl;
	buildGame();
	play();
}

// destructor
Game::~Game() {
	delete p1;
	delete p2;
}

// takes in the sentence and the min and max of possible inputs
// prints the message until input is an int and in range
int Game::getValidIntegerInput(string message, int min, int max) {
	int input;

	std::cout << message;

	while (!(std::cin >> input) || input < min || input > max) {
		cout << message;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return input;
}

// sets number of rounds for the game to play and sets the dice based on input
void Game::buildGame() {
	int numSides = 0;

	this->numOfRounds = getValidIntegerInput("How many rounds will be played? ", 1, INT_MAX);

	// ternary operator deals with the return and converting it to a string
	this->p1DieType = getValidIntegerInput("What type of die will Player 1 use?\n1. Normal\n2. Loaded\n", 1, 2) == 1 ? "normal" : "loaded";
	numSides = getValidIntegerInput("How many sides should Player 1's die have? ", 4, INT_MAX);
	this->p1 = p1DieType == "normal" ? new Die(numSides) : new LoadedDie(numSides);

	this->p2DieType = getValidIntegerInput("What type of die will Player 2 use?\n1. Normal\n2. Loaded\n", 1, 2) == 1 ? "normal" : "loaded";
	numSides = getValidIntegerInput("How many sides should Player 2's die have? ", 4, INT_MAX);
	this->p2 = p2DieType == "normal" ? new Die(numSides) : new LoadedDie(numSides);
}

// for each round, to numOfRounds, roll the correct type of die, compare
// the rolls, increment the winners score, and print the round
void Game::play() {
	int p1Score = 0;
	int p2Score = 0;
	int ties = 0;

	for (int i = 0; i < numOfRounds; i++) {
		p1CurrentRoll = p1->roll();
		p2CurrentRoll = p2->roll();
		if (p1CurrentRoll > p2CurrentRoll) {
			p1Score++;
		}
		else if (p2CurrentRoll > p1CurrentRoll) {
			p2Score++;
		}
		else {
			ties++;
		}
		printGame(i + 1, p1Score, p2Score, ties);
	}
}


void Game::printGame(int currentTurn, int p1Score, int p2Score, int ties) {
	cout << endl << "Round #" << currentTurn << endl;
	cout << "Player 1s " << p1DieType << " die rolled: " << p1CurrentRoll << endl;
	cout << "Player 2s " << p2DieType << " die rolled: " << p2CurrentRoll << endl;
	
	string roundWinner;
	if (p1CurrentRoll > p2CurrentRoll) {
		roundWinner = "Player 1 won";
	}
	else if (p2CurrentRoll > p1CurrentRoll) {
		roundWinner = "Player 2 won";
	}
	else if (p1CurrentRoll = p2CurrentRoll) {
		roundWinner = "Players 1 and 2 tied";
	}

	cout << roundWinner << " Round #" << currentTurn << "!" << endl;
	cout << "Rounds won:\tPlayer 1: " << p1Score << "\tPlayer 2: " << p2Score << "\tTies: " << ties <<  endl;
	
	if (currentTurn == numOfRounds) {
		if (p1Score > p2Score) {
			cout << endl << "Player 1 won the game!" << endl;
		}
		else if (p2Score > p1Score) {
			cout << endl << "Player 2 won the game!" << endl;
		}
		else if (p2Score = p1Score) {
			cout << endl << "Player 1 and Player 2 tied with a score of " << p1Score << "." << endl;
		}
	}
}


int main() {
	int choice = 0;
	Game *game;
	
	choice = Game::getValidIntegerInput("1. Start War Dice\n2. Quit\nEnter the number of your choice: ", 1, 2);
	switch (choice) {
	case 1:
		game = new Game();
		delete game;
		break;
	default: 
		break;
	}
	return 0;
}