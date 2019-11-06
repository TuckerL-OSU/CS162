/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
* Game.cpp
******************************************************************************/
#include "Game.hpp"

Game::Game() {
	play();
}

Game::~Game() {

}

void Game::play() {
	int choice = 0;

	do {
		chooseChar();
		while (p1->getStrength_Points() > 0 && p2->getStrength_Points() > 0) {		
			Character::combat(p1, p2);
		}
		if (p1) {
			delete p1;
		}

		if (p2) {
			delete p2;
		}
	} while (playAgain());
}

void Game::createChar(int choice, int player) {
	Character *creating = nullptr;

	switch (choice) {
	case 1: creating = new Vampire();
		break;
	case 2: creating = new Barbarian();
		break;
	case 3: creating = new BlueMen();
		break;
	case 4: creating = new Medusa();
		break;
	case 5: creating = new HarryPotter();
		break;
	default: 
		break;
	}
	
	if (player == 1)
		p1 = creating;
	else
		p2 = creating;

	creating = nullptr;
	if (creating) {
		delete creating;
	}
}

void Game::chooseChar() {
	int choice1 = 0;
	int choice2 = 0;

	cout << "1. Vampire" << endl;
	cout << "2. Barbarian" << endl;
	cout << "3. Blue Men" << endl;
	cout << "4. Medusa" << endl;
	cout << "5. Harry Potter" << endl;

	choice1 = getValidInteger("Who will attack first? ", 1, 5);
	createChar(choice1, 1);

	choice2 = getValidInteger("Who will defend first? ", 1, 5);
	createChar(choice2, 2);

	if (choice2 == choice1) {
		p1->setName(p1->getName().append("_1"));
		p2->setName(p2->getName().append("_2"));
	}
}

int main() {
	srand(time(NULL));

	Game *game = new Game();

	delete game;

	return 0;
}