/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 7: Circular Linked List with Queues
* Queue.cpp
******************************************************************************/
#include "Queue.hpp"

Queue::Queue() {
	head = nullptr;
}

Queue::~Queue() {
	while (!isEmpty()) {
		removeFront();
	}
	if (head == nullptr) {
		delete head;
	}
}

bool Queue::isEmpty() {
	return head == nullptr;
}

void Queue::addBack(int value) {	
	if (isEmpty()) {
		head = new QueueNode(value);
		head->prev = head;
		head->next = head;
	}
	else {
		head->prev->next = new QueueNode(value);
		head->prev->next->next = head;
		head->prev->next->prev = head->prev;
		head->prev = head->prev->next;
	}
}

int Queue::getFront() {
	if (!isEmpty()) {
		return head->val;
	}
	else {
		return NULL;
	}
}

void Queue::removeFront() {
	if (isEmpty()) {
		cout << "There are no values in the queue currently." << endl;
	}
	// deletes the head if it is the last node
	else if (head->next == head) {
		QueueNode *temp = head;
		head = nullptr;
		delete temp;
	}
	// deletes nodes up to the head
	else {
		QueueNode *temp = head;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		delete temp;
	}
}

void Queue::printQueue() {
	if (!isEmpty()) {
		// node to print
		QueueNode *current = head;
		while (current->next != head) {
			cout << current->val << " -> ";
			current = current->next;
		}
		cout << current->val << endl;

		current = nullptr;
		delete current;
	}
	else {
		cout << "Empty!" << endl;
	}
	cout << endl;
	
}