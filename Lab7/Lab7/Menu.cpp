/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 7: Circular Linked List with Queues
* Menu.cpp
******************************************************************************/
#include "Queue.hpp"
#include "Support.hpp"

void menu() {
	Queue *list = new Queue();
	int input = 0;

	do {
		cout << "1. Enter a value to be added at the back of queue.\n";
		cout << "2. Display first node (front) value.\n";
		cout << "3. Remove first node (front) value.\n";
		cout << "4. Display the queue contents.\n";
		cout << "5. Exit\n";
		input = getValidInteger("Choose an action: ", 1, 5);

		int number = 0;
		switch (input) {
		case 1: 
			number = getValidInteger("Enter a number to add at the back: ", INT_MIN, INT_MAX);
			list->addBack(number);
			cout << endl;
			break;
		case 2:
			if (list->getFront() == NULL) {
				cout << "There are no values in the queue currently." << endl;
			}
			else {
				cout << list->getFront() << " is at the front of the queue." << endl;
			}
			cout << endl;
			break;
		case 3: 
			if (list->getFront() != NULL) {
				cout << list->getFront() << " was removed from the queue." << endl;
				list->removeFront();
			}
			else {
				cout << "There are no values in the queue currently." << endl;
			}
			cout << endl;
			break;
		case 4: 
			cout << "The current queue is: ";
			list->printQueue();
			break;
		default:
			break;
		}

	} while (input != 5);

	delete list;
}

int main() {
	menu();
	return 0;
}
