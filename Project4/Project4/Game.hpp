/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* Game.hpp
******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Queue.hpp"

class Game {
public:
	Game();
	~Game();

	Queue *t1;
	Queue *t2;
	Queue *losers;

	void chooseChar(int, int);
	void createChar(int, int);
	void createTeam(Queue* , Character*);
	void bench(Queue*, Character*);
	void requeue(Queue*, Character*);
	void play();

	int numOfFighters;
	int numOfTeams;
	int t1Score;
	int t2Score;

};

#endif // !GAME_HPP