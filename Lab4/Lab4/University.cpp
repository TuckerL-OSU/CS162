/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* University.cpp
******************************************************************************/
#include "University.hpp"

University::University() {
	uniName = "Oregon State University";

}

University::~University() {

}

void University::setUniName(string name) {
	this->uniName = name;
}
string University::getUniName() {
	return uniName;
}

// adds a building to the info system
void University::addBuilding(Building* building) {
	buildings.push_back(building);
}

// adds a person to the info system
void University::addPerson(Person* person) {
	people.push_back(person);
}

// prints info about all the buildings on OSU
void University::buildingInfo() {
	cout << "Buildings of " << getUniName() << ":"<< endl;
	for (Building* building : buildings) {
		cout << "\tName: " << building->getBuildName() << endl;
		cout << "\tAddress: " << building->getBuildAddress() << endl;
		cout << "\tSqft: " << building->getBuildSize() << endl << endl;
	}
}

// prints info about the people of the university
void University::peopleInfo() {
	cout << "People of " << getUniName() << ":" << endl;
	for (Person* person : people) {
		person->printInfo();
	}
}

// prints a list of all the people at the uni, 
// then asks who to do work and prints 
void University::work() {
	int input = 0;
	cout << "People that have work to do:" << endl;
	for (int i = 0; i < people.size(); i++) {
		cout << "\t" << i + 1 << ". " << people[i]->getName() << endl;
	}
	input = getValidIntegerInput("Choose the person to do work: ", 1, people.size());
	people[input - 1]->printWork();

}