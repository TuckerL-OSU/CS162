#include "RPSGame.hpp"

RPSGame::RPSGame() {
	srand(time(NULL));
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
	start();
}

RPSGame::~RPSGame() {
	delete player;
	delete computer;

	for (Tool* t : player_choices) {
			delete t;
	}
}

void RPSGame::start() {
	char input = ' ';

	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	cout << "Do you want to choose different strengths for the tools? (y-yes, n-no): ";
	input = getCharInput();
	switch (input) {
	case 'y':
		// @@@@@@@@@@@@do something about setting tool strengths
		play();
		break;
	case 'n': // default game
		play();
		break;
	default:
		break;
	}
}

void RPSGame::play() {
	bool endGame = true;
	char input = ' ';
	int computerChoice = 0;
	States outcome;

	while (endGame) {
		cout << "Choose your tool (r-rock, p-paper, s-scissor, e-exit): ";
		player = generateTool(getCharInput());
		computerChoice = RNG(1, 3);
		switch (computerChoice) {
		case 1: // rock
			computer = generateTool('r');
			break;
		case 2: // paper
			computer = generateTool('p');
			break;
		case 3: // scissors
			computer = generateTool('s');
			break;
		default:
			break;
		}

		player_choices.push_back(player);
		computer_choices.push_back(player);

		cout << "Computer chose " << computer->getType() << "." << endl;

		outcome = player->fight(computer);
		switch (outcome) {
		case WIN: 
			cout << "You win!!!" << endl;
			human_wins++;
			break;
		case LOSS: 
			cout << "Computer wins! :-(" << endl;
			computer_wins++;
			break;
		case DRAW:
			cout << "Tie!" << endl;
			ties++;
			break;
		default:
			break;
		}

		cout << "Human wins: " << human_wins << endl;
		cout << "Computer wins: " << computer_wins << endl;
		cout << "Ties: " << ties << endl;
	}

}

Tool* RPSGame::generateTool(char tool) {
	switch (tool) {
	case 'r':
		return new Rock();
		break;
	case 'p':
		return new Paper();
		break;
	case 's':
		return new Scissors();
		break;
	case 'e': exit(0);
		break;
	default:
		break;
	}
}
