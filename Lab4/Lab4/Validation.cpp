/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Validation.cpp
******************************************************************************/
#include "Validation.hpp"

// input validation I have used for the last few assignments
// basically turns my mutliple choice questions into a switch
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
