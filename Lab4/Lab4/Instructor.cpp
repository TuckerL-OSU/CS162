/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Instructor.cpp
******************************************************************************/
#include "Instructor.hpp"

Instructor::Instructor() {
	rating = 1.0;
}

Instructor::Instructor(double rating, string name, int age) : Person(name, age) {
	this->rating = rating;
}

Instructor::~Instructor() {
}

int Instructor::do_work() {
	return rand() % 60 + 0;
}

void Instructor::setRating(double rating) {
	this->rating = rating;
}
double Instructor::getRating() {
	return rating;
}

void Instructor::printWork() {
	cout << this->getName() << " graded papers for " << do_work() << " hours." << endl;
}

void Instructor::printInfo() {
	Person::printInfo();
	cout << "\tRating: " << setprecision(1) << rating << endl << endl;
}