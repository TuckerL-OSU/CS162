#include "Support.hpp"

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

// takes in string inputs to set them properly
string getStringInput() {
	string input = "";

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, input);
	return input;
}

char getCharInput() {
	char input = ' ';

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> input;
	return tolower(input);
}

// random number gen
int RNG(int min, int max) {
	return rand() % (max - min + 1) + min;
}