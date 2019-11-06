/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Student.cpp
******************************************************************************/
#include "Student.hpp"

Student::Student() {
	GPA = 1.0;
}

Student::Student(double GPA, string name, int age) : Person(name, age) {
	this->GPA = GPA;
}

Student::~Student() {
}

int Student::do_work() {
	return rand() % 60 + 0;
}

void Student::setGPA(double GPA) {
	this->GPA = GPA;
}
double Student::getGPA() {
	return GPA;
}

void Student::printWork() {
	cout << this->getName() << " did " << do_work() << " hours of homework." << endl;
}

void Student::printInfo() {
	Person::printInfo();
	cout << "\tGPA: " << setprecision(1) << GPA << endl << endl;
}