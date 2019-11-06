/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Building.cpp
******************************************************************************/
#include "Building.hpp"
#include <string>

using std::string;

Building::Building()
{
	buildName = "Home";
	buildAddress = "The Moon";
	buildSize = 0;
}

Building::~Building()
{
}

void Building::setBuildName(string name) {
	this->buildName = name;
}
string Building::getBuildName() {
	return buildName;
}

void Building::setBuildAddress(string address) {
	this->buildAddress = address;
}
string Building::getBuildAddress() {
	return buildAddress;
}

void Building::setBuildSize(int sqft) {
	this->buildSize = sqft;
}
int Building::getBuildSize() {
	return buildSize;
}
