/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Animal.cpp
******************************************************************************/
#include "Animal.hpp"

Animal::Animal() {
	age = 0;
	cost = 0.00;
	numberOfBabies = 0;
	baseFoodCost = 10.00;
	payoff = 0;
}

Animal::~Animal() {
	
}

void Animal::setAge(int age) {
	this->age = age;
}

void Animal::setCost(double cost) {
	this->cost = cost;
}

void Animal::setNumberOfBabies(int numberOfBabies) {
	this->numberOfBabies = numberOfBabies;
}

void Animal::setBaseFoodCost(double baseFoodCost) {
	this->baseFoodCost = baseFoodCost;
}

void Animal::setPayoff(double payoff) {
	this->payoff = payoff;
}

int Animal::getAge() {
	return age;
}

bool Animal::isAdult() {
	if (age >= 3)
		return true;
	else
		return false;
}

double Animal::getCost() {
	return cost;
}

int Animal::getNumberOfBabies() {
	return numberOfBabies;
}

double Animal::getBaseFoodCost() {
	return baseFoodCost;
}

double Animal::getPayoff() {
	return payoff;
}