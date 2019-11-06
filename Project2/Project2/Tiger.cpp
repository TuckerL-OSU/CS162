/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Tiger.cpp
******************************************************************************/
#include "Tiger.hpp"

Tiger::Tiger() {
	this->age = 0;
	this->cost = 10000.00;
	this->numberOfBabies = 1;
	this->baseFoodCost = getBaseFoodCost() * 5;
	this->payoff = cost * 0.2;
}

Tiger::~Tiger() {

}

void Tiger::setBaseFoodCost(double baseFoodCost) {
	this->baseFoodCost = baseFoodCost;
}

double Tiger::getBaseFoodCost() {
	return baseFoodCost;
}

void Tiger::setAge(int age) {
	this->age = age;
}

int Tiger::getAge() {
	return age;
}