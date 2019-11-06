/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 1: Langton's Ant Simulation
* Main.cpp
******************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <time.h>
#include "Ant.hpp"
using std::cout;
using std::cin;
using std::endl;

// http://www.cplusplus.com/forum/beginner/21595/
int checkInput(int input) {
	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return input;
}

int randomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void simMenu(int simType) {
	int numRows = 0;
	int numCols = 0;
	int numSteps = 0;
	int startRow = 0;
	int startCol = 0;

	do {
		cout << "How many rows should the board have? ";
		numRows = checkInput(numRows);
	} while (numRows < 2);
	do {
		cout << "How many cols should the board have? ";
		numCols = checkInput(numCols);
	} while (numCols < 2);
	do {
		cout << "How many steps should the simulation run? ";
		numSteps = checkInput(numSteps);
	} while (numSteps == 0);

	if (simType == 1) {
		do {
			cout << "What row should the ant start on? ";
			startRow = checkInput(startRow);
		} while (startRow == 0 || startRow > numRows);
		do {
			cout << "What column should the ant start on? ";
			startCol = checkInput(startCol);
		} while (startCol == 0 || startCol > numCols);
	}
	else {
		//generate numbers
		startRow = randomNumber(1, numRows);
		startCol = randomNumber(1, numCols);
	}

	Ant ant(numRows, numCols, numSteps, startRow, startCol);
	ant.start();
}

void mainMenu() {
	int choice = 0;

	do {
		cout << "1. Start Langton's Ant" << endl;
		cout << "2. Start Lantgon's Ant at a random location" << endl;
		cout << "3. Quit" << endl;
		switch (checkInput(choice)) {
		case 1: simMenu(1); break;
		case 2: simMenu(2); break;
		case 3: exit(0); break;
		default: cout << "Enter the number of your choice." << endl; break;
		}
	} while (choice != 3);

}

int main() {
	srand(time(NULL));
	mainMenu();
	return 0;
}