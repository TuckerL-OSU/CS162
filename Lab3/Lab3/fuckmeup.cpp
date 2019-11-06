#include "Game.hpp"
#include <typeinfo>

Game::Game() {
	menu();
}

Game::Game(int turns, string p1Die, int p1Sides, string p2Die, int p2Sides) {
	this->numOfRounds = turns;
	this->p1DieType = p1Die;
	this->p2DieType = p2Die;

	if (p1DieType == "normal") {
		this->p1 = new Die(p1Sides);
	}
	else {
		this->p1 = new LoadedDie(p1Sides);
	}

	if (p2DieType == "normal") {
		this->p2 = new Die(p2Sides);
	}
	else {
		this->p2 = new LoadedDie(p2Sides);
	}

	play();
}

void Game::play() {
	int p1Score = 0;
	int p2Score = 0;

	for (int i = 0; i < numOfRounds; i++) {
		p1CurrentRoll = p1->roll();
		p2CurrentRoll = p2->roll();
		if (p1CurrentRoll > p2CurrentRoll) {
			p1Score++;
		}
		else if (p2CurrentRoll > p1CurrentRoll) {
			p2Score++;
		}
		else {
			p1Score++;
			p2Score++;
		}
		printGame(i + 1, p1Score, p2Score);
	}
}

Game::~Game() {
	delete p1;
	delete p2;
}


int Game::checkIntInput(int input, string message) {
	//do {
	//	cout << message;
	//	cin >> input;
	//	//if (input )
	//	//if (cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')) {
	//	//	cin.clear();
	//	//}
	//	cin.clear();
	//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//	return input;
	//} while (!(cin >> input) || input < 1);

	while (!(std::cin >> input) || input < 1) {
		cout << message;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return input;

}

string Game::checkDieType(string playerDieType, string message) {
	do {
		cout << message;
		cin >> playerDieType;
		if (playerDieType == "normal") {
			return "normal";
		}
		else if (playerDieType == "loaded") {
			return "loaded";
		}
		else {
			cin.clear();
			cout << message;
		}
	} while (!(cin >> playerDieType));
}

int getIntegerInput(string message) {
	int n;

	while (!(std::cin >> n)) {
		std::cout << message;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return n;
}

void Game::getUserInput() {
	int numRounds = 0;
	string player1Die = "normal";
	int player1Sides = 0;
	string player2Die = "loaded";
	int player2Sides = 0;
	//do {
		//numOfRounds = getIntegerInput(numOfRounds, "How many rounds will be played? ");
		//player1Die = checkDieType(player1Die, "What type of die will Player 1 use? ");
		//player1Sides = getIntegerInput(player1Sides, "How many sides should Player 1's die have? ");
		//player2Die = checkDieType(player2Die, "What type of die will Player 2 use? ");
		//player2Sides = getIntegerInput(player2Sides, "How many sides should Player 2's die have? ");
		numOfRounds = getIntegerInput("How many rounds will be played? ");
		// player1Die = checkDieType("What type of die will Player 1 use? ");
		player1Sides = getIntegerInput("How many sides should Player 1's die have? ");
		// player2Die = checkDieType("What type of die will Player 2 use? ");
		player2Sides = getIntegerInput("How many sides should Player 2's die have? ");

	//} while (numRounds == 0 || player1Sides == 0 || player2Sides == 0);

	Game game(numOfRounds, player1Die, player1Sides, player2Die, player2Sides);
}

void Game::printGame(int currentTurn, int p1Score, int p2Score) {
	cout << endl << "Round #" << currentTurn << endl;
	cout << "Player 1s " << p1DieType << " die rolled: " << p1CurrentRoll << endl;
	cout << "Player 2s " << p2DieType << " die rolled: " << p2CurrentRoll << endl;
	string roundWinner;

	if (p1CurrentRoll > p2CurrentRoll) {
		roundWinner = "Player 1 won";
	}
	else if (p2CurrentRoll > p1CurrentRoll) {
		roundWinner = "Player 2 won";
	}
	else if (p1CurrentRoll = p2CurrentRoll) {
		roundWinner = "Players 1 and 2 tied";
	}
	cout << roundWinner << " Round #" << currentTurn << "!" << endl;
	cout << "Rounds won:\tPlayer 1: " << p1Score << "\tPlayer 2: " << p2Score << endl;
	
	if (currentTurn == numOfRounds) {
		if (p1Score > p2Score) {
			cout << endl << "Player 1 won the game!" << endl;
		}
		else if (p2Score > p1Score) {
			cout << endl << "Player 2 won the game!" << endl;
		}
		else if (p2Score = p1Score) {
			cout << endl << "Player 1 and Player 2 tied with a score of " << p1Score << "." << endl;
		}
	}
}

void Game::menu() {
	int choice = 0;

	//do {
	//	cout << "1. Start War Dice" << endl;
	//	cout << "2. Quit" << endl;
	//	switch (checkIntInput(choice, "Enter the number of your choice: ")) {
	//	case 1: Game::getUserInput(); break;
	//	case 2: exit(0); break;
	//	default: break;
	//	}
	//} while (choice != 2);

	do {
		cout << "1. Start War Dice" << endl;
		cout << "2. Quit" << endl;
		choice = getIntegerInput("Enter the number of your choice: ");
		switch (choice) {
		case 1: Game::getUserInput(); break;
		case 2: exit(0); break;
		default: break;
		}
	} while (choice != 2);

}


int main() {
	//Die die1(50);
	//LoadedDie die2(50);
	//Game game(10, "loaded", 20, "normal", 20);

	Game game;




	//for (int i = 0; i < 10; i++) {
	//	cout << die1.roll() << " "  << die2.roll() << endl;
	//}
	//srand(time(NULL));
	//mainMenu();

	return 0;
}

int LoadedDie::loadMod(int originalRoll) {
	if (originalRoll == N) {
		return originalRoll;
	}
	else if (originalRoll + (0.1 * N) >= N) {
		return N;
	}
	else {
		return originalRoll + (0.1 * N);
	}
}
