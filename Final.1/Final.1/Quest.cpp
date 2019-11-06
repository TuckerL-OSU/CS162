/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Quest.cpp
******************************************************************************/
#include "Quest.hpp"

Quest::Quest() {
	srand(time(NULL));
	moonStonesFound = 0;
	success = false;
	north = "1. North";
	south = "2. South";
	east = "3. East";
	west = "4. West";
	inventory = "5. Show Inventory";
	validMove = true;
	ash = new Player();
	board = new Board();
	questLength = 20;

}

Quest::~Quest() {
	delete ash;
	delete board;
}

void Quest::mainMenu() {
	//do {
		clearScreen();
		//board = new Board();
		//ash = new Player();


		cout << "Help the Clefairys!" << endl;
		cout << "The Clefairys need help collecting moonstones so they can go back to the moon." << endl;
		cout << "Collect " << ash->bp->getCapacity() << " moonstones to evolve the Clefairys, so they can fly their rocket." << endl;
		cout << "Starting from \"C\" work your way around the board to \"R\"" << endl;
		cout << "You must collect moonstones \"X\" along the way or you will not be able to help!" << endl;
		cout << "You only have " << questLength << " minutes(turns) before the sun rises! Be Quick!" << endl;
		cout << endl;

		turn();

		if (!success) {
			cout << "You were not able to help the Clefairys in time!" << endl;
		}
		
		//delete ash;
		//delete board;


	//} while (playAgain());
}

void Quest::turn() {
	for (static int i = 0; i < questLength; i++) {
		int move = 0;

		if (i == 0) {
			ash->setLoc(ROWS / 2, COLS / 2);
		}
		cout << "Turn " << i + 1 << endl;
		board->printBoard();
		do {
			move = questMenu();
			clearScreen();
			action(move);
		} while (!validMove);

		// game ended successfully
		if (success) {
			i = 0;
			break;
		}
	}
}

// appends new to the direction if that room hasnt been visited yet
int Quest::questMenu() {
	int choice = 0;

	if ((ash->getY() - 1) >= 0) {
		cout << north;
		if (board->gameBoard[ash->getY() - 1][ash->getX()]->state == UNVISITED 
			|| board->gameBoard[ash->getY() - 1][ash->getX()]->state == ROCKET 
			|| board->gameBoard[ash->getY() - 1][ash->getX()]->state == MOONSTONE) {
			cout << " (new)" << endl;
		}
		else {
			cout << endl;
		}
	}

	if ((ash->getY() + 1) < ROWS) {
		cout << south;
		if (board->gameBoard[ash->getY() + 1][ash->getX()]->state == UNVISITED
			|| board->gameBoard[ash->getY() + 1][ash->getX()]->state == ROCKET
			|| board->gameBoard[ash->getY() + 1][ash->getX()]->state == MOONSTONE) {
			cout << " (new)" << endl;
		}
		else {
			cout << endl;
		}
	}
		
	if ((ash->getX() + 1) < COLS) {
		cout << east;
		if (board->gameBoard[ash->getY()][ash->getX() + 1]->state == UNVISITED 
			|| board->gameBoard[ash->getY()][ash->getX() + 1]->state == ROCKET
			|| board->gameBoard[ash->getY()][ash->getX() + 1]->state == MOONSTONE) {
			cout << " (new)" << endl;
		}
		else {
			cout << endl;
		}
	}

	if ((ash->getX() - 1) >= 0) {
		cout << west;
		if (board->gameBoard[ash->getY()][ash->getX() - 1]->state == UNVISITED 
			|| board->gameBoard[ash->getY()][ash->getX() - 1]->state == ROCKET
			|| board->gameBoard[ash->getY()][ash->getX() - 1]->state == MOONSTONE) {
			cout << " (new)" << endl;
		}
		else {
			cout << endl;
		}
	}

	if (ash->bp->getSize() > 0) {
		cout << inventory << endl;
	}

	choice = getValidInteger("What Room would you like to go to? ", 1, 5);
	cout << endl;
	
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
	case 5: {
		if (ash->bp->getSize() == 0) {
			cout << "Your inventory is empty! There is nothing to see." << endl;
			cout << endl;
		}
		else {
			ash->bp->printInv();
		}
		turn();
	}
		break;
	default:
		break;
	}
}

void Quest::moveNorth() {
	validMove = board->checkMove(ash->getY() - 1, ash->getX());
	if (moveResult(validMove)) {
		encounter(ash->getY() - 1, ash->getX());
		board->move(ash->getY() - 1, ash->getX(), NORTH);
		ash->setY(ash->getY() - 1);
	}
}

void Quest::moveSouth() {
	validMove = board->checkMove(ash->getY() + 1, ash->getX());
	if (moveResult(validMove)) {
		encounter(ash->getY() + 1, ash->getX());
		board->move(ash->getY() + 1, ash->getX(), SOUTH);
		ash->setY(ash->getY() + 1);
	}
}

void Quest::moveEast() {
	validMove = board->checkMove(ash->getY(), ash->getX() + 1);
	if (moveResult(validMove)) {
		encounter(ash->getY(), ash->getX() + 1);
		board->move(ash->getY(), ash->getX() + 1, EAST);
		ash->setX(ash->getX() + 1);
	}
}

void Quest::moveWest() {
	validMove = board->checkMove(ash->getY(), ash->getX() - 1);
	if (moveResult(validMove)) {
		encounter(ash->getY(), ash->getX() - 1);
		board->move(ash->getY(), ash->getX() - 1, WEST);
		ash->setX(ash->getX() - 1);
	}
}

bool Quest::moveResult(bool result) {
	if (result == false) {
		cout << "Choose a valid move!" << endl;
		cout << endl;
		turn();
	}
	else {
		return true;
	}
}

void Quest::encounter(int Y, int X) {
	if (board->gameBoard[Y][X]->state == UNVISITED
		&& ash->bp->getSize() != ash->bp->getCapacity()) {
		if (board->gameBoard[Y][X]->event() == 1) {
			ash->bp->addToInv("Rock");
		}
	}
	if (board->gameBoard[Y][X]->state == CLEFAIRY) {
		questLength += board->gameBoard[Y][X]->event();
	}
	if (board->gameBoard[Y][X]->state == MOONSTONE) {
		if (board->gameBoard[Y][X]->event() == 1) {
			ash->bp->addToInv("MoonStone");
			moonStonesFound++;
		}
	}
	if (board->gameBoard[Y][X]->state == ROCKET) {
		if (moonStonesFound == board->moonStones) {
			success = board->gameBoard[Y][X]->event();
			cout << "You Successfully helped the Clefairy's Evolve so they can use their Rocket!" << endl;
		}
		else {
			cout << "You need to find 3 MoonStones before you can enter the Rocket Room!" << endl;
			cout << endl;
			turn();
		}
	}
}

int main() {
	do {
		Quest *q = new Quest();
		q->mainMenu();
		delete q;
	} while (playAgain());

	return 0;
}