/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* University.hpp
******************************************************************************/
#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP
#include <iostream>
#include <vector>
#include "Validation.hpp"
#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class University
{
public:
	University();
	~University();

	void setUniName(string);
	string getUniName();

	void buildingInfo();
	void peopleInfo(); // operator ovld?

	void addBuilding(Building*);
	void addPerson(Person*);
	void work();

private:
	string uniName;
	vector<Building*> buildings;
	vector<Person*> people;

};

#endif