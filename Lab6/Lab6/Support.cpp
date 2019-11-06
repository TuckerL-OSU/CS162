/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 6: Linked List
* Support.cpp
******************************************************************************/
#include "Support.hpp"

int getValidIntegerInput(string message, int min, int max) {
	int input;

	cout << message;
	// Continuously prompt the user, until they enter an accepted input
	while (!(cin >> input) || input < min || input > max) {
		cout << message << endl;
		// Clear stdin to prevent infinite loops
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input;
}
