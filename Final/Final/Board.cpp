/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Board.cpp
******************************************************************************/
#include "Board.hpp"

//Board::Board() {
//	for (int i = 0; i < ROWS; i++) {
//		for (int j = 0; j < COLS; j++) {
//			gameBoard[i][j] = UNVISITED;
//		}
//	}
//
//	setHome();
//	setRocket();
//}

// http://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/
// possibly not the only one I used, but this was the first thing that I found
// which pointed me in the right direction
Board::Board(const int rows, const int cols) {
	head = nullptr;
	Space *current = nullptr;
	Space *currentHead = nullptr;
	Space *prev = nullptr;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			// maybe mem leak
			if (i == 0 && j == 0) {
				Space *room = new EmptyRoom();
				head = room;
				current = head;
			}
			if (i == 0 && j > 0) {
				Space *room = new EmptyRoom();
				room->setWest(current);
				current->setEast(room);
				head->setEast(current);
				if (j == COLS - 1) {
					current = head;
				}
			}
			if (i > 0 && j == 0) {
				Space *room = new EmptyRoom();
				prev = current;
				room->setNorth(prev);
				prev->setSouth(room);
				current = room;
				currentHead = room;
				prev->setEast(prev->getEast());
			}
			if (i > 0 && j > 0) {
				Space *room = new EmptyRoom();
				room->setWest(current);
				current->setEast(room);
				current->setNorth(prev);
				if (j == COLS - 1) {
					prev = currentHead->getNorth();
				}
			}
			if (i == ROWS - 1 && j == 0) {
				Space *room = new EmptyRoom();
				prev = current;
				room->setNorth(prev);
				prev->setSouth
			}
		}
	}

	setHome();
	setRocket();
}

Board::~Board() {
	
}

void Board::addSpace() {

}

void Board::setHome() {
	gameBoard[ROWS / 2][COLS / 2] = CLEFAIRY;
	location = new HomeRoom(ROWS / 2, COLS / 2);
}

void Board::setRocket() {
	int rocketRow = RNG(0, ROWS - 1);
	int rocketCol = RNG(0, COLS - 1);

	if (gameBoard[rocketRow][rocketCol] == CLEFAIRY) {
		setRocket();
	}
	else {
		gameBoard[rocketRow][rocketCol] = ROCKET;
	}
}

int Board::move(int row, int col, Direction direction) {
	// out of bounds move
	if ((row > ROWS - 1 && row < 0) || (col > COLS - 1 && col < 0)) {
		return 1;
	}
	// good move
	else if (gameBoard[row][col] == UNVISITED) {
		gameBoard[row][col] = CURRENT;
		return 2;
	}
	// return to a previous room
	else {
		gameBoard[row][col] = (SpaceState)direction;
		switch (direction) {
		case NORTH: gameBoard[row + 1][col] = CURRENT;
			break;
		case SOUTH: gameBoard[row - 1][col] = CURRENT;
			break;
		case EAST: gameBoard[row][col + 1] = CURRENT;
			break;
		case WEST: gameBoard[row][col - 1] = CURRENT;
			break;
		default:
			break;
		}
		return 3;
	}
}

void Board::printBoard() {
	for (int i = 0; i < ROWS; i++) {
		cout << "|---+---+---+---+---|" << endl;
		cout << "| ";
		for (int j = 0; j < COLS; j++) {
			cout << (char)gameBoard[i][j] << " | ";
		}
		cout << endl;
	}
	cout << "|---+---+---+---+---|" << endl;
}

