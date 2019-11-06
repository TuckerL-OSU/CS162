/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Game.cpp
******************************************************************************/
#include "Game.hpp"
#include "Validation.hpp"

Game::Game() {
	cout << "Setting up the zoo..." << endl;
	srand(time(NULL));
	zoo = new Zoo();
	zoo->buildZoo();
	cout << "Lets play Zoo Tycoon!" << endl;
	play();
}

// destructor
Game::~Game() {
	delete zoo;
}

void Game::play() {
	bool endGame = true;
	double bonus = 0.00;

	while (endGame) {
		zoo->begOfDay();

		bonus = zoo->dailyEvent();
		cout << "Todays income: $" << zoo->calcIncome() + bonus << endl;
		zoo->bank += zoo->calcIncome() + bonus;
		cout << "Bank Value: $" << zoo->bank << endl;
		if (zoo->bank == 0.00) {
			cout << "Game Over! You're Broke!" << endl;
			endGame = false;
		}
		else {
			zoo->buyAnimal();
			endGame = zoo->endOfDay();
		}
	}
}

int main() {
	int choice = 0;
	Game *game;

	choice = getValidIntegerInput("1. Start Zoo Tycoon\n2. Quit\nEnter the number of your choice: ", 1, 2);
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