#include <iostream>
#include "Ant.hpp"
#include "Array.hpp"

using std::cout;
using std::endl;
using std::cin;

Ant::Ant(int numRows, int numCols) {
	this->numRows = numRows;
	this->numCols = numCols;
	this->posX = startRow;
	this->posY = numCols / 2;
	this->orientation = 0;

	board = AllocateDynamicArray<SlotState>(numRows, numCols);
	clearBoard();
}

Ant::~Ant() {
	FreeDynamicArray<SlotState>(board);
}

void Ant::toggleSlot() {
	if (board[posX][posY] == WHITE) {
		board[posX][posY] = BLACK;
	}
	else {
		board[posX][posY] = WHITE;
	}
}

void Ant::move() {
	// original orientation of ant
	int deltaX = 0;
	int deltaY = 1;


	for (int stepNum = 0; stepNum < 11000; stepNum++) {
		if(stepNum > 10250)
			printBoard();

		if (board[posX][posY] == BLACK) {
			// Turn Left
			turnLeft(deltaX, deltaY);
		}
		else {
			// Turn Right
			turnRight(deltaX, deltaY);
		}

		toggleSlot();
		posX += deltaX;
		posY += deltaY;
	}
}

void Ant::turnLeft(int &deltaX, int &deltaY) {
	if (deltaX == 0) {
		deltaX = -deltaY;
		deltaY = 0;
	}
	else {
		deltaY = deltaX;
		deltaX = 0;
	}
}
//
void Ant::turnRight(int &deltaX, int &deltaY) {
	if (deltaX == 0) {
		deltaX = deltaY;
		deltaY = 0;
	}
	else {
		deltaY = -deltaX;
		deltaX = 0;
	}
}

void Ant::start() {
		move();
}

void Ant::printBoard() {
	cout << "+";
	for (int i = 0; i < numCols; i++) {
		cout << "-";
	}
	cout << "+" << endl;

	for (int i = 0; i < numRows; i++){
		cout << "|";
		for (int j = 0; j < numCols; j++) {
			if (i == posX && j == posY) {
				cout << "*";
			}
			else {
				cout << (char)board[i][j];
			}
		}
		cout << "|" << endl;
	}

	cout << "+";
	for (int i = 0; i < numCols; i++) {
		cout << "-";
	}
	cout << "+" << endl;
}

void Ant::clearBoard() {
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			board[i][j] = WHITE;
		}
	}

}


