/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Quest.cpp
******************************************************************************/
#include "Quest.hpp"

Quest::Quest() {
	questLength = 20;
	north = "1. North";
	south = "2. South";
	east = "3. East";
	west = "4. West";
	inventory = "5. Show Inventory";
}

Quest::~Quest() {

}

void Quest::mainMenu() {
	//int choice = 0;

	//Game *game;

	//cout << "1. Play Fantasy Combat Tournament" << endl;
	//cout << "2. Quit" << endl;
	//choice = getValidInteger("Which would you like to do? ", 1, 2);

	//switch (choice) {
	//case 1:
	//	game = new Game();
	//	delete game;
	//	break;
	//default:
	//	break;
	//}
	do {
		board = new Board();
		ash = new Player();


		cout << "Help the Clefairys!" << endl;
		cout << "The Clefairys need help collecting moonstones so they can go back to the moon." << endl;
		cout << "Collect " << ash->bp->getCapacity() << " moonstones to restore power to their rocket." << endl;
		cout << "Starting from \"C\" work your way around the board to \"R\"" << endl;
		cout << "You must collect moonstones along the way or you will not be able to help!" << endl;
		cout << "You only have " << questLength << " moves before the sun rises! Be Quick!" << endl;

		turn();

		delete ash;
		delete board;

	} while (playAgain());
}

void Quest::turn() {
	for (int i = 0; i < questLength; i++) {
		int move = 0;

		if (i = 0) {
			ash->setLoc(ROWS / 2, COLS / 2);
		}
		if (i != 0) {
			cout << "Turn " << i << endl;
		}
		board->printBoard();
		move = questMenu();
		action(move);
	}
}

int Quest::questMenu() {
	int choice = 0;

	if ((ash->getY() - 1) < ROWS) {
		cout << north;
		if (board->gameBoard[ash->getY() - 1][ash->getX()] == (UNVISITED && ROCKET)) {
			cout << " (new)" << endl;
		}
		else {
			cout << endl;
		}
	}

	if ((ash->getY() + 1) >= 0) {
		cout << south;
		if (board->gameBoard[ash->getY() + 1][ash->getX()] == (UNVISITED && ROCKET)) {
			cout << " (new)" << endl;
		}
		else {
			cout << endl;
		}
	}
		
	if ((ash->getX() + 1) < COLS) {
		cout << east;
		if (board->gameBoard[ash->getY()][ash->getX() + 1] == (UNVISITED && ROCKET)) {
			cout << " (new)" << endl;
		}
		else {
			cout << endl;
		}
	}

	if ((ash->getX() - 1) >= 0) {
		cout << west;
		if (board->gameBoard[ash->getY()][ash->getX() - 1] == (UNVISITED && ROCKET)) {
			cout << " (new)" << endl;
		}
		else {
			cout << endl;
		}
	}

	if (ash->bp->getSize() > 0) {
		cout << inventory << endl;
	}

	choice = getValidInteger("What would you like to do? ", 1, 5);
	
	return choice;
}

void Quest::action(int whereToGo) {
	switch (whereToGo) {
	case 1:
		moveNorth();
		break;
	case 2:
		moveSouth();
		break;
	case 3:
		moveEast();
		break;
	case 4: 
		moveWest();
		break;
	case 5:
		if (ash->bp->getSize() == 0) {
			cout << "Your inventory is empty! There is nothing to see." << endl;
		}
		else {
			ash->bp->printInv();
		}
		questMenu();
		break;
	default:
		break;
	}
}

void Quest::moveNorth() {
	int result = 0;

	result = board->move(ash->getY() - 1, ash->getX(), NORTH);
	ash->setY(ash->getY() - 1);
	moveResult(result);
}

void Quest::moveSouth() {
	int result = 0;

	result = board->move(ash->getY() + 1, ash->getX(), SOUTH);
	ash->setY(ash->getY() + 1);
	moveResult(result);
}

void Quest::moveEast() {
	int result = 0;

	result = board->move(ash->getY(), ash->getX() + 1, EAST);
	ash->setX(ash->getX() + 1);
	moveResult(result);
}

void Quest::moveWest() {
	int result = 0;

	result = board->move(ash->getY(), ash->getX() - 1, WEST);
	ash->setX(ash->getX() - 1);
	moveResult(result);
}

void Quest::moveResult(int result) {
	if (result == 1) {
		cout << "Choose a valid move!" << endl;
		questMenu();
	}
	else {
		return;
	}
}

int main() {
	srand(time(NULL));
	Quest *q = new Quest();

	q->mainMenu();
	//Board *board = new Board();
	//board->printBoard();
	//delete board;

	//Player *p = new Player(2, 2);
	//p->bp->addToInv("pants");
	//p->bp->addToInv("grass");
	//p->bp->addToInv("glass");
	//p->bp->addToInv("helium");
	//p->bp->addToInv("neon");
	//delete p;

	delete q;

	return 0;
}