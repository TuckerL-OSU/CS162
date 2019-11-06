#ifndef RPSGAME_HPP
#define RPSGAME_HPP
#include "Tool.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"
#include "Support.hpp"
#include <vector>

using std::vector;

class RPSGame {
private:
	Tool* player;
	Tool* computer;
	int human_wins;
	int computer_wins;
	int ties;
	vector<Tool*> player_choices;
	vector<Tool*> computer_choices;

public:
	RPSGame();
	~RPSGame();
	void play();
	void start();
	Tool* generateTool(char);
};

#endif // !RPSGAME_HPP