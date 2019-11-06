/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 6: Linked List
* Menu.cpp
******************************************************************************/
#include "DoublyLinkedList.hpp"
#include "Support.hpp"

void menu() {
	DoublyLinkedList *list = new DoublyLinkedList();
	int input = 0;

	do {
		cout << "1. Add a new node to the head.\n";
		cout << "2. Add a new node to the tail.\n";
		cout << "3. Delete the first node in the list.\n";
		cout << "4. Delete the last node in the list.\n";
		cout << "5. Traverse the list reversely.\n";
		cout << "6. Traverse the list.\n";
		cout << "7. Print the value of the Node the head is pointing to.\n";
		cout << "8. Print the value of the Node the tail is pointing to.\n";
		cout << "9. Exit\n";
		input = getValidIntegerInput("Choose an action: ", 1, 9);

		int number = 0;
		switch (input) {
		case 1: number = getValidIntegerInput("Enter a number to add to the head: ", INT_MIN, INT_MAX);
			list->insertHead(number);
			list->forwardTraverse();
			break;
		case 2: number = getValidIntegerInput("Enter a number to add to the tail: ", INT_MIN, INT_MAX);
			list->insertTail(number);
			list->forwardTraverse();
			break;
		case 3: list->deleteFirst();
			list->forwardTraverse();
			break;
		case 4: list->deleteLast();
			list->forwardTraverse();
			break;
		case 5: list->reverseTraverse();
			break;
		case 6: list->forwardTraverse();
			break;
		case 7: list->printValAtHead();
			break;
		case 8: list->printValAtTail();
			break;
		default:
			break;
		}

	} while (input != 9);
	
	delete list;
}

int main() {
	menu();
	return 0;
}
