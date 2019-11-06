/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Backpack.cpp
******************************************************************************/
#include "Backpack.hpp"

Backpack::Backpack() {
	this->capacity = 3;
}

Backpack::~Backpack() {

}

int Backpack::getSize() {
	return inventory.size();
}

int Backpack::getCapacity() {
	return capacity;
}

bool Backpack::invFull() {
	return getSize() == capacity;
}

void Backpack::addToInv(string item) {
	if (!invFull()) {
		inventory.push_back(item);
		cout << "Picked up: " << item << endl;
		cout << getSize() << "/" << capacity << " items in your inventory." << endl;
	}
	else {
		cout << "Your inventory is full!" << endl;
		removeFromInv();
		addToInv(item);
	}
}

void Backpack::removeFromInv() {
	int toDrop = 0;

	printInv();

	// -1 to account for indicies
	toDrop = getValidInteger("Choose an item to drop: ", 1, 3) - 1;

	inventory.erase(inventory.begin() + toDrop);
}

void Backpack::printInv() {
	for (int i = 0; i < getSize(); i++) {
		cout << i + 1 << ". " << inventory[i] << "\t";
	}
	cout << endl;
}