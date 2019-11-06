/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 6: Linked List
* DoublyLinkedList.hpp
******************************************************************************/
#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "Node.hpp"
#include "Support.hpp"


class DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void insertHead(int);
	void insertTail(int);
	void deleteFirst();
	void deleteLast();
	void forwardTraverse();
	void reverseTraverse();
	void printValAtHead();
	void printValAtTail();
	bool isEmpty();

private:
	Node *head;
	Node *tail;
	Node *temp;
	int size;
};


#endif // !DOUBLYLINKEDLIST_HPP
