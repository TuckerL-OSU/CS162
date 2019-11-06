/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Board.cpp
******************************************************************************/
#include "Board.hpp"

Board::Board() {
	this->moonStones = 3;
	counter = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			gameBoard[i][j] = new EmptyRoom();
		}
	}

	setHome();
	setRocket();
	setMoonStones();
}

Board::~Board() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			delete gameBoard[i][j];
		}
	}
}

void Board::setHome() {
	delete gameBoard[ROWS / 2][COLS / 2];
	gameBoard[ROWS / 2][COLS / 2] = new HomeRoom();
}

void Board::setRocket() {
	int rocketRow = 0; 
	int rocketCol = 0; 

	rocketRow = RNG(0, ROWS - 1);
	rocketCol = RNG(0, COLS - 1);

	if (gameBoard[rocketRow][rocketCol]->state != CLEFAIRY) {
		delete gameBoard[rocketRow][rocketCol];
		gameBoard[rocketRow][rocketCol] = new RocketRoom();
	}
	else {
		setRocket();
	}
}

void Board::setMoonStones() {
	for (counter; counter < moonStones; counter++) {
		int stoneRow = 0;
		int stoneCol = 0;

		stoneRow = RNG(0, ROWS - 1);
		stoneCol = RNG(0, COLS - 1);

		if (gameBoard[stoneRow][stoneCol]->state != CLEFAIRY
			&& gameBoard[stoneRow][stoneCol]->state != ROCKET
			&& gameBoard[stoneRow][stoneCol]->state != MOONSTONE) {
			delete gameBoard[stoneRow][stoneCol];
			gameBoard[stoneRow][stoneCol] = new ItemRoom();
		}
		else {
			setMoonStones();
		}
	}
}

bool Board::checkMove(int row, int col) {
	if ((row > ROWS - 1 || row < 0) || (col > COLS - 1 || col < 0)) {
		return false;
	}
	else {
		return true;
	}
}

void Board::move(int row, int col, Direction direction) {
	if (gameBoard[row][col]->state != CLEFAIRY && gameBoard[row][col]->state != ROCKET) {
		gameBoard[row][col]->state = CURRENT;
	}
	switch (direction) {
	case NORTH:
		if (gameBoard[row + 1][col]->state != CLEFAIRY && gameBoard[row + 1][col]->state != ROCKET) {
			gameBoard[row + 1][col]->state = (SpaceState)direction;
			//gameBoard[row + 1][col]->state = VISITED;
		}
		break;
	case SOUTH:
		if (gameBoard[row - 1][col]->state != CLEFAIRY && gameBoard[row - 1][col]->state != ROCKET) {
			gameBoard[row - 1][col]->state = (SpaceState)direction;
			//gameBoard[row - 1][col]->state = VISITED;
		}
		break;
	case EAST:
		if (gameBoard[row][col - 1]->state != CLEFAIRY && gameBoard[row][col - 1]->state != ROCKET) {
			gameBoard[row][col - 1]->state = (SpaceState)direction;
			//gameBoard[row][col - 1]->state = VISITED;
		}
		break;
	case WEST:
		if (gameBoard[row][col + 1]->state != CLEFAIRY && gameBoard[row][col + 1]->state != ROCKET) {
			gameBoard[row][col + 1]->state = (SpaceState)direction;
			//gameBoard[row][col + 1]->state = VISITED;
		}
		break;
	default:
		break;
	}
}

void Board::printBoard() {
	for (int i = 0; i < ROWS; i++) {
		for (int k = 0; k < ROWS; k++) {
			cout << "+---";
		}
		cout << "+" << endl;
		cout << "| ";
		for (int j = 0; j < COLS; j++) {
			cout << (char)gameBoard[i][j]->state << " | ";
		}
		cout << endl;
	}
	for (int l = 0; l < COLS; l++){
		cout << "+---";
	}
	cout << "+" << endl;
}

