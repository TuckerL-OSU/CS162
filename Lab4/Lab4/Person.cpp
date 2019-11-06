/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Person.cpp
******************************************************************************/
#include "Person.hpp"

Person::Person() {
	name = "nun";
	age = 0;
}

Person::Person(string name, int age) {
	this->name = name;
	this->age = age;
}

Person::~Person()
{
}

// assume total work for week; 0-60 hrs
int Person::do_work() {
	return 0;
}

void Person::setName(string personName) {
	this->name = personName;
}
string Person::getName() {
	return name;
}

void Person::setAge(int personAge) {
	this->age = personAge;
}
int Person::getAge() {
	return age;
}

void Person::printWork() {
	cout << "Default person working..." << endl;
}

// prints the name and age of the person read,
// the type of person appends gpa or rating
void Person::printInfo() {
	cout << "\tName: " << getName() << endl;
	cout << "\tAge: " << getAge() << endl;
	cout << fixed;
}