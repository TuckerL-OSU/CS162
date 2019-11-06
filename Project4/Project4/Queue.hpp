/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat continued
* Queue.cpp
******************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Support.hpp"
#include "Character.hpp"

class Queue {
public:
	struct QueueNode {
		Character* fighter;
		QueueNode *next;
		QueueNode *prev;
		QueueNode(Character* teamMate) {
			fighter = teamMate;
		}
	};
	QueueNode *head;

	Queue();
	~Queue();

	bool isEmpty();
	void addBack(Character*);
	void addFront(Character*);
	int checkFighters(Character*);
	Character* getFighter();
	void removeFighter();
	void printQueue();

};


#endif // !QUEUE_HPP
