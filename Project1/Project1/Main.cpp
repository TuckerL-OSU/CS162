#include <iostream>
#include "Ant.hpp"
using std::cout;
using std::cin;
using std::endl;

void simMenu() {
	int numRows;
	int numCols;
	int numSteps;
	int startRow;
	int startCol;

	do {
		cout << "How many rows should the board have? ";
		cin >> numRows;
		cout << "How many columns should the board have? ";
		cin >> numCols;
		cout << "How many steps should the simulation run? ";
		cin >> numSteps;
		cout << "What row should the ant start on?";
		cin >> startRow;
		cout << "What column should the ant start on?";
		cin >> startCol;
		Ant::Ant(numRows, numCols);

	} while (false);
}

void mainMenu() {
	int choice;
	
	do {
		cout << "1. Start Langton's Ant simulation" << endl;
		cout << "2. Quit" << endl;
		cin >> choice;
		switch (choice) {
		case 1: simMenu(); break;
		case 2: exit(0);
		default: cout << "Enter the number of your choice."; break;
		}
	} while (choice != 2);
}

int main() {
	Ant ant(70, 70);

	ant.start();

	return 0;
}