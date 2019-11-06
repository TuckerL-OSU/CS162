//
//  Stack.cpp
//  Lab9
//
//  Created by Tucker Lavell on 11/23/17.
//

#include "Stack.hpp"

Stack::Stack(string userInput) {
	this->original = userInput;
	this->reverse = "";
}

Stack::~Stack() {
	delete[] letters;
}

// turn the string into an array of chars
void Stack::stringToChar() {
	letters = new char[original.size()];

	for (int i = 0; i < original.size(); i++) {
		letters[i] = original[i];
	}
}

// breaks the string up and adds it to a stack 1 letter a time
void Stack::toStack() {
	//stringToChar();

	for (int i = 0; i < original.size(); i++) {
		stackOfLetters.push(letters[i]);
	}
}

// returns the letter on the top of the stack, and deletes it from the stack
char Stack::getReverse() {
	char letter = stackOfLetters.top();
	stackOfLetters.pop();
	return letter;
}


void Stack::createPalindrome() {
	stringToChar();
	toStack();
}

void Stack::printPalindrome() {
	cout << "The palindrome of \"" << original << "\" is: ";
	cout << original;

	while (!stackOfLetters.empty()) {
		cout << getReverse();
	}
	cout << endl << endl;
}