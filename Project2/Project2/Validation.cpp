/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Validation.cpp
******************************************************************************/
#include "Validation.hpp"

int getValidIntegerInput(string message, int min, int max) {
	int input;

	cout << message;

	while (!(cin >> input) || input < min || input > max) {
		cout << message;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input;
}
