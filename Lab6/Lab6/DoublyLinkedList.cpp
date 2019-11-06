/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 6: Linked List
* DoublyLinkedList.cpp
******************************************************************************/
#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList() {
	size = 0;
	head = new Node();
	tail = new Node();

	head->next = tail;
	tail->prev = head;
}

DoublyLinkedList::~DoublyLinkedList() {
	if (head && head->prev != nullptr) {
		delete head;
	}

	if (tail && tail->next != nullptr) {
		delete tail;
	}

	if (temp && (temp->next != nullptr || temp->prev != nullptr)) {
		delete temp;
	}

}

void DoublyLinkedList::insertHead(int data) {
	temp = new Node();
	temp->setVal(data);

	if (isEmpty()) {
		head = temp;
		tail = temp;
		++size;
	}
	else {
		temp->next = head;
		head->prev = temp;
		head = temp;
		++size;
	}
	temp = nullptr;
	delete temp;
}

void DoublyLinkedList::insertTail(int data) {
	temp = new Node();
	temp->setVal(data);

	if (isEmpty()) {
		head = temp;
		tail = temp;
		++size;
	}
	else {
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		++size;
	}
	temp = nullptr;
	delete temp;
}

void DoublyLinkedList::deleteFirst() {
	if (!isEmpty()) {
		temp = head->next;
		head = temp;
		--size;
	}
	else {
		cout << "The list is empty! ";
	}
}

void DoublyLinkedList::deleteLast() {
	if (!isEmpty()) {
		temp = tail->prev;
		tail = temp;
		--size;
	}
	else {
		cout << "The list is empty! ";
	}
}

void DoublyLinkedList::forwardTraverse() {
	temp = head;

	if (!isEmpty()) {
		for (int i = 0; i < size; i++) {
			if (i + 1 == size) {
				cout << temp->val << endl;
			}
			else {
				cout << temp->val << " -> ";
			}
			temp = temp->next;
		}
	}
	else {
		cout << "There are no values to traverse! " << endl;
	}
	cout << endl;
}

void DoublyLinkedList::reverseTraverse() {
	temp = tail;

	if (!isEmpty()) {
		for (int i = 0; i < size; i++) {
			if (i + 1 == size) {
				cout << temp->val << endl;
			}
			else {
				cout << temp->val << " -> ";
			}
			temp = temp->prev;
		}
	}
	else {
		cout << "There are no values to traverse! " << endl;
	}
	cout << endl;
}

void DoublyLinkedList::printValAtHead() {
	if (!isEmpty()) {
		cout << "Value of the node the head is pointing to: " << head->getVal() << endl;
	}
	else {
		cout << "There are no nodes!" << endl;
	}
}

void DoublyLinkedList::printValAtTail() {
	if (!isEmpty()) {
		cout << "Value of the node the tail is pointing to: " << tail->getVal() << endl;
	}
	else {
		cout << "There are no nodes!" << endl;
	}
}

bool DoublyLinkedList::isEmpty() {
	if (size == 0) {
		return true;
	}
	else
		return false;
}