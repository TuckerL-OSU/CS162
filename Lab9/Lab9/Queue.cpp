//
//  Queue.cpp
//  Lab9
//
//  Created by Tucker Lavell on 11/23/17.
//

#include "Queue.hpp"

Queue::Queue(int rounds, int toAdd, int toDelete) {
	this->rounds = rounds;
	this->chanceToAdd = toAdd;
	this->chanceToDelete = toDelete;
	this->avgLength = 0;
}

Queue::~Queue() {

}

int Queue::numToAdd() {
	int numToAdd = RNG(1, 1000);

	return numToAdd;
}

bool Queue::addBack() {
	int chance = RNG(1, 100);

	return (chance <= chanceToAdd);
}

bool Queue::deleteFront() {
	int chance = RNG(1, 100);

	return (chance <= chanceToDelete);
}

void Queue::createBuffer() {
	for (int i = 0; i < rounds; i++) {
		if (addBack()) {
			int number = numToAdd();
			buffer.push(number);
		}

		if (deleteFront() && !buffer.empty()) {
			buffer.pop();
		}
		calcAvgLength(i + 1);
	}
}

void Queue::calcAvgLength(int round) {
	avgLength = ((avgLength) * (round - 1) + buffer.size()) / round;
}

void Queue::printBufferInfo() {
	cout << "The buffer contains: ";
	queue<int> copy = buffer;
	while (!copy.empty()) {
		cout << copy.front() << " ";
		copy.pop();
	}
	cout << endl;
	cout << "The length of the buffer is: " << buffer.size() << endl;
	cout << "The average length of the buffer is: " << avgLength << endl;
	cout << endl;
}