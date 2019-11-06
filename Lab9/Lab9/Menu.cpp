//
//  Menu.cpp
//  Lab9
//
//  Created by Tucker Lavell on 11/22/17.
//

#include "Menu.hpp"

int main() {
	int input = 0;

	do {
		cout << "1. Buffer Simulation" << endl;
		cout << "2. Palindrome" << endl;
		cout << "3. Exit" << endl;
		input = getValidInteger("Choose the number of your action: ", 1, 3);

		switch (input) {
		case 1: 
			buffer();
			break;
		case 2:
			palindrome();
			break;
		default: break;
		}
	} while (input != 3);

	return 0;
}

void buffer() {
	int rounds = 0;
	int chanceToAdd = 0;
	int chancetoDelete = 0;

	rounds = getValidInteger("How many rounds do you want to simulate? ", 0, INT_MAX);
	chanceToAdd = getValidInteger("What is the percentage chance to add a number at the end of the buffer? ", 0, 100);
	chancetoDelete = getValidInteger("What is the percentage chance to remove a number at the front of the buffer? ", 0, 100);

	Queue *buffer = new Queue(rounds, chanceToAdd, chancetoDelete);
	buffer->createBuffer();

	buffer->printBufferInfo();

	delete buffer;
}

void palindrome() {
	string userString = "";

	userString = getStringInput("What word would you like to turn into a palindrome? ");
	Stack *palindrome = new Stack(userString);

	palindrome->createPalindrome();

	palindrome->printPalindrome();

	delete palindrome;
}