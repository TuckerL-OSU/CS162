#include "RPSGame.hpp"

int main() {
	int choice = 0;
	RPSGame *game;

	cout << "1. Play Rock, Paper, Scissors" << endl;
	cout << "2. Quit" << endl;
	choice = getValidIntegerInput("Enter the number of your choice: ", 1, 2);
	switch (choice) {
	case 1:
		game = new RPSGame();
		delete game;
		break;
	default:
		break;
	}
	return 0;
}