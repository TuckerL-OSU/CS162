/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 6: Linked List
* Node.hpp.cpp
******************************************************************************/
#ifndef NODE_HPP
#define NODE_HPP

class Node {
private: 
	int val;
	Node *prev;
	Node *next;
	friend class DoublyLinkedList;

public:
	Node();
	Node(int, Node*, Node*);
	~Node();
	void setVal(int);
	virtual int getVal();
};



#endif // !NODE_HPP

