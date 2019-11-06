/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 1: Langton's Ant Simulation
* Ant.cpp
******************************************************************************/
#include <iostream>
#include "Ant.hpp"
#include "Array.hpp"

using std::cout;
using std::endl;
using std::cin;

Ant::Ant(int numRows, int numCols, int numSteps, int posRow, int posCol) {
	this->numRows = numRows;
	this->numCols = numCols;
	this->posRow = posRow - 1;
	this->posCol = posCol - 1;
	this->numOfSteps = numSteps;

	board = AllocateDynamicArray<SlotState>(numRows, numCols);
	clearBoard();
}

Ant::~Ant() {
	FreeDynamicArray<SlotState>(board, numRows);
}

void Ant::toggleSlot() {
	if (board[posRow][posCol] == WHITE) {
		board[posRow][posCol] = BLACK;
	}
	else {
		board[posRow][posCol] = WHITE;
	}
}

void Ant::move() {
	// tracks orientation of ant
	// original orientation of ant is East
	int deltaRow = 0; // 1 = south -1 = north
	int deltaCol = 1; // 1 = east -1 = west


	for (int stepNum = 0; stepNum < numOfSteps; stepNum++) {
		printBoard();

		if (board[posRow][posCol] == BLACK) {
			// Turn Left
			turnLeft(deltaRow, deltaCol);
		}
		else {
			// Turn Right
			turnRight(deltaRow, deltaCol);
		}

		toggleSlot();
		posRow += deltaRow;
		posCol += deltaCol;

		// rows
		if (posRow < 0)
			posRow = numRows - 1;

		if (posRow > numRows - 1)
			posRow = 0;
		// cols
		if (posCol < 0)
			posCol = numCols - 1;

		if (posCol > numCols - 1)
			posCol = 0;
	}
}

//changes the orientation of the ant based off the value of the deltas
void Ant::turnLeft(int &deltaRow, int &deltaCol) {
	if (deltaRow == 0) {
		deltaRow = -deltaCol;
		deltaCol = 0;
	}
	else {
		deltaCol = deltaRow;
		deltaRow = 0;
	}
}

void Ant::turnRight(int &deltaRow, int &deltaCol) {
	if (deltaRow == 0) {
		deltaRow = deltaCol;
		deltaCol = 0;
	}
	else {
		deltaCol = -deltaRow;
		deltaRow = 0;
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

	for (int i = 0; i < numRows; i++) {
		cout << "|";
		for (int j = 0; j < numCols; j++) {
			if (i == posRow && j == posCol) {
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

// changes all the slots in the array back to white
void Ant::clearBoard() {
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			board[i][j] = WHITE;
		}
	}

}


