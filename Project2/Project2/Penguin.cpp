/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Penguin.cpp
******************************************************************************/
#include "Penguin.hpp"

Penguin::Penguin() {
	this->age = 0;
	this->cost = 1000.00;
	this->numberOfBabies = 5;
	this->baseFoodCost = getBaseFoodCost();
	this->payoff = cost * .1;
}

Penguin::~Penguin() {

}

void Penguin::setBaseFoodCost(double baseFoodCost) {
	this->baseFoodCost = baseFoodCost;
}

double Penguin::getBaseFoodCost() {
	return baseFoodCost;
}

void Penguin::setAge(int age) {
	this->age = age;
}

int Penguin::getAge() {
	return age;
}