/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Turtle.cpp
******************************************************************************/
#include "Turtle.hpp"

Turtle::Turtle() {
	this->age = 0;
	this->cost = 100.00;
	this->numberOfBabies = 10;
	this->baseFoodCost = getBaseFoodCost() * 0.5;
	this->payoff = cost * 0.05;
}

Turtle::~Turtle() {

}

void Turtle::setBaseFoodCost(double baseFoodCost) {
	this->baseFoodCost = baseFoodCost;
}

double Turtle::getBaseFoodCost() {
	return baseFoodCost;
}

void Turtle::setAge(int age) {
	this->age = age;
}

int Turtle::getAge() {
	return age;
}