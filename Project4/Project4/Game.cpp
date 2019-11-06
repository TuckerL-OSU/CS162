/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* Game.cpp
******************************************************************************/
#include "Game.hpp"

Game::Game() {
	numOfTeams = 2;
	numOfFighters = 0;
	t1Score = 0;
	t2Score = 0;
	play();
}

Game::~Game() {
	//if (t1 != nullptr) {
	//	t1 = nullptr;
	//	delete t1;
	//}
	//
	//if (t2 != nullptr) {
	//	t2 = nullptr;
	//	delete t2;
	//}
	//if (losers != nullptr) {
	//	losers = nullptr;
	//	delete losers;
	//}
}

void Game::play() {
	char choice = ' ';

	do {
		numOfFighters = getValidInteger("How many fighters per team do you want? ", 1, INT_MAX);

		t1 = new Queue();
		t2 = new Queue();
		losers = new Queue();
		for (int i = 1; i <= numOfTeams; i++) {
			cout << "Choose Team " << i << endl;
			cout << "1. Vampire" << endl;
			cout << "2. Barbarian" << endl;
			cout << "3. Blue Men" << endl;
			cout << "4. Medusa" << endl;
			cout << "5. Harry Potter" << endl;
			for (int j = 1; j <= numOfFighters; j++) {
				chooseChar(i, j);
			}
		}
		while (!t1->isEmpty() && !t2->isEmpty()) {
			Character::combat(t1->getFighter(), t2->getFighter());

			if (t1->getFighter()->getStrength_Points() <= 0) {
				bench(t1, t1->getFighter());
				requeue(t2, t2->getFighter());
				t2Score += 2;
				t1Score -= 1;
			}
			else if (t2->getFighter()->getStrength_Points() <= 0) {
				bench(t2, t2->getFighter());
				requeue(t1, t1->getFighter());
				t1Score += 2;
				t2Score -= 1;
			}
			else
				return;
		}

		cout << "Team 1 Score: " << t1Score << endl;
		cout << "Team 2 Score: " << t2Score << endl;

		if (t1Score > t2Score) {
			cout << "Team 1 Won the Tournament!";
		}
		else if (t2Score > t1Score) {
			cout << "Team 2 Won the Tournament! ";
		}
		else {
			cout << "The Tournament Ended with a Tie!";
		}
		cout << endl;

		choice = getCharInput("Would you like to see the losers? (y-yes or any letter to continue): ");
		if (choice == 'y') {
			cout << "The losers from last to first: " << endl;
			losers->printQueue();
		}

		if (t1) {
			//t1 = nullptr;
			delete t1;
		}
		if (t2) {
			//t2 = nullptr;
			delete t2;
		}
		if (losers) {
			//losers = nullptr;
			delete losers;
		}
		t1Score = 0;
		t2Score = 0;

	} while (playAgain());
}

void Game::bench(Queue *team, Character *loser) {
	Character *temp = loser;
	losers->addFront(loser);
	team->removeFighter();
	temp = nullptr;
	delete temp;
}

void Game::requeue(Queue *team, Character *winner) {
	winner->recoveryRoll();
	team->addBack(winner);
}

void Game::createTeam(Queue *team, Character *fighter) {
	static int numOnTeam = 0;

	team->addBack(fighter);
	numOnTeam++;

	if (numOnTeam > 1) {
		int numOfSameName = team->checkFighters(fighter);
		if (numOfSameName != 0) {
			// + 1 because I want dupe names to start at #2
			fighter->setName(fighter->getName().append(" #" +
				to_string(numOfSameName + 1)));
		}

	}


	if (numOnTeam == numOfFighters) {
		numOnTeam = 0;
	}

}

void Game::createChar(int choice, int team) {
	Character *creating = nullptr;
	string name = "";

	switch (choice) {
	case 1: creating = new Vampire();
		break;
	case 2: creating = new Barbarian();
		break;
	case 3: creating = new BlueMen();
		break;
	case 4: creating = new Medusa();
		break;
	case 5: creating = new HarryPotter();
		break;
	default:
		break;
	}

	// enter gives them default name
	name = getStringInput("Give them a name(or just press enter to continue): ");
	if (name != "") {
		creating->setName(name);
	}

	creating->setName(creating->getName().insert(0, "T" + to_string(team) + "_"));

	if (team == 1) {
		createTeam(t1, creating);
	}
	//else if (team == 2) {
	else {
		createTeam(t2, creating);
	}

	//if (creating != nullptr) {
	//	creating = nullptr;
	//	delete creating;
	//}
}


void Game::chooseChar(int team, int fighterOrder) {
	int choice = 0;

	choice = getValidInteger("Team " + to_string(team)
		+ " Fighter " + to_string(fighterOrder) + ": ", 1, 5);
	createChar(choice, team);
}

void menu() {
	srand(time(NULL));

	int choice = 0;

	Game *game;

	cout << "1. Play Fantasy Combat Tournament" << endl;
	cout << "2. Quit" << endl;
	choice = getValidInteger("Which would you like to do? ", 1, 2);

	switch (choice) {
	case 1:
		game = new Game();
		delete game;
		break;
	default:
		break;
	}
}

int main() {

	menu();

	return 0;
}