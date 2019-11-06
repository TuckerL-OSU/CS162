/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the function implementations of the for various
 * functons contained in the Support file
***************************************/
#include "Support.hpp"

/**
 * Function for prompting the user for an integer, gettinf input
 * from the user, and validating the input
 * @param void
 * @return int
 * -	User's input
 * @param int min
 * -	Minimum value the user can enter
 * @param int max
 * -	Maximum value the user can enter
 **/
int getValidInteger(string message, int min, int max) {
	string str = "";
	int newStr = 0;
	bool intCheck = false;

	cout << message;
	while (!intCheck) {
		cin >> str;
		stringstream stream(str);

		if (stream >> newStr) {
			string remainingStr;
			getline(stream, remainingStr);

			if (newStr < min || newStr > max) {
				cout << message;
			}
			else if (remainingStr == "") {
				intCheck = true;
			}
			else {
				cout << message;
			}
		} else {
			cout << message;
		}
	}
	return newStr;
}

/**
 * Function for getting a string input from the user
 * @param void
 * @return string input
 * - User's input string
 **/
string getStringInput() {
	string input = "";
	// Clear stdin to accept input
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, input);
	return input;
}

/**
 * Funtion for getting a character input from the user
 * @param void
 * @return char input
 * -	User's input
 **/
char getCharInput(string message) {
	char input = ' ';
	string str = "";
	bool charCheck = false;
	// Clear stdin to accept input
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << message;
	while (!charCheck) {
		cin >> str;
		stringstream stream(str);

		if (stream >> input) {
			string remainingStr;
			getline(stream, remainingStr);

			if (remainingStr == "") {
				charCheck = true;
			}
			else {
				cout << message;
			}

		}
		else {
			cout << message;
		}
	}
	return tolower(input);
}

/**
 * Function for generating a random number
 * @param int min
 * -	Lower bound for the range
 * @param int max
 * -	Upper bound for the range
 * @return int
 * -	A random number from the range of min and max
 **/
int RNG(int min, int max) {
	return (rand() % max) + min;
}

/**
 * Function prompts the user for whether they'd like to
 * continue playing the Rock, Paper, Scissors game.
 * @param void
 * @return bool
 * -	Whether the user would like to continue
 **/
bool playAgain() {
	int tempChoice = 0;

	std::cout << "Would you like to play again?" << std::endl;
	std::cout << "1. Yes." << std::endl;
	std::cout << "2. No." << std::endl;

	tempChoice = getValidInteger("Enter an option: ", 1, 2);

	switch (tempChoice) {
	case 1:
		return true;
		break;
	case 2:
		return false;
		break;
	default:
		return 0;
	}
}
