/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 4: Fantasy Combat Game Pt2
* Queue.cpp
******************************************************************************/
#include "Queue.hpp"

Queue::Queue() {
	head = nullptr;
}

Queue::~Queue() {
	while (!isEmpty()) {
		removeFighter();
	}
	if (head == nullptr) {
		delete head;
	}
}

bool Queue::isEmpty() {
	return head == nullptr;
}

void Queue::addBack(Character* nextFighter) {
	if (isEmpty()) {
		head = new QueueNode(nextFighter);
		head->prev = head;
		head->next = head;
	}
	// for shuffling the queue to add winners back to the end
	else if (head->fighter == nextFighter) {
		head->prev->next = head;
		head->prev->next->prev = head->prev;
		head = head->next;
	}
	else {
		head->prev->next = new QueueNode(nextFighter);
		head->prev->next->next = head;
		head->prev->next->prev = head->prev;
		head->prev = head->prev->next;
	}
}

void Queue::addFront(Character* loser) {
	if (isEmpty()) {
		head = new QueueNode(loser);
		head->prev = head;
		head->next = head;
	}
	else {
		head->prev->next = new QueueNode(loser);
		head->prev->next->next = head;
		head->prev->next->prev = head->prev;
		head = head->prev->next;
	}
}

int Queue::checkFighters(Character* fighterAdding) {
	int sameName = 0;
	QueueNode *current = head;
	
	// stops at the fighter we just added
	while (current->next != head) {
		// searches for the beginning part of the name T1_Name, T2_Name
		if (current->fighter->getName().find(fighterAdding->getName()) == 
			fighterAdding->getName().find(fighterAdding->getName())) {
			sameName++;
		}
		current = current->next;
	}
	return sameName;
}

Character* Queue::getFighter() {
	if (!isEmpty()) {
		return head->fighter;
	}
	else {
		return NULL;
	}
}

void Queue::removeFighter() {
	if (isEmpty()) {
		cout << "There are no Fighters in the queue currently." << endl;
	}
	// deletes the head if it is the last node
	else if (head->next == head) {
		QueueNode *temp = head;
		head = nullptr;
		delete temp;
	}
	// deletes nodes up to the head
	else {
		//// semi functioning
		QueueNode *temp = head;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		delete temp;

		//QueueNode *temp = head;
		//head->prev->next = head->next;
		//head->prev->next->prev = head->prev;
		//head->next->prev = head->prev;
		//head = head->next;

		//delete temp;

	}
}

void Queue::printQueue() {
	if (!isEmpty()) {
		// node to print
		QueueNode *current = head;
		while (current->next != head) {
			cout << current->fighter->getName() << " -> ";
			current = current->next;
		}
		cout << current->fighter->getName() << endl;

		current = nullptr;
		delete current;
	}
	else {
		cout << "Empty!" << endl;
	}
	cout << endl;

}