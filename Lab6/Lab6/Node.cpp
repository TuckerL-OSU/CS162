#include "Node.hpp"

Node::Node() {
	val = 0;
	next = nullptr;
	prev = nullptr;
}

Node::Node(int v, Node *n, Node *p) {
	this->val = v;
	this->next = n;
	this->prev = p;
}

Node::~Node() {
	if (next && prev == nullptr) {
		delete next;
		//next = nullptr;
	}

	if (prev && next == nullptr) {
		delete prev;
		//prev = nullptr;
	}
}

void Node::setVal(int v) {
	this->val = v;
}

int Node::getVal() {
	return val;
}