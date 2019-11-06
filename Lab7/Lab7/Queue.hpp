/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 7: Circular Linked List with Queues
* Queue.cpp
******************************************************************************/
#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP
#include "Support.hpp"

class Queue {
	struct QueueNode {
		int val;
		QueueNode *next;
		QueueNode *prev;
		QueueNode(int value) {
			val = value;
		}
	};
	QueueNode *head;

public:
	Queue();
	~Queue();

	bool isEmpty();
	void addBack(int);
	int getFront();
	void removeFront();
	void printQueue();

};


#endif // !QUEUENODE_HPP