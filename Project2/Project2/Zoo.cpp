/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 2: Zoo Tycoon
* Zoo.cpp
******************************************************************************/
#include "Zoo.hpp"
#include "Validation.hpp"
#include <limits>

Zoo::Zoo() {
	this->bank = 100000.00;
	this->animalCapacity = 10;
	this->numOfCurrentAnimals = 0;
	this->numTigers = 0;
	this->numPenguins = 0;
	this->numTurtles = 0;
	this->numSpecies = 0;
	this->income = 0.00;
	this->dayOfOp = 0;
	tigers = new Tiger[animalCapacity];
	penguins = new Penguin[animalCapacity];
	turtles = new Turtle[animalCapacity];
	animals = new Animal[animalCapacity];
}

Zoo::~Zoo() {
	delete[] tigers;
	delete[] penguins;
	delete[] turtles;
	delete[] animals;

}

// put the initial animals in the zoo
void Zoo::buildZoo() {
	cout << "Building a zoo..." << endl;
	this->numTigers = getValidIntegerInput("Would you like to buy 1 or 2 Tigers? ", 1, 2);
	fillZoo(tigers, Tiger(), numTigers, 1);
	numSpecies++;

	this->numPenguins = getValidIntegerInput("Would you like to buy 1 or 2 Penguins? ", 1, 2);
	fillZoo(penguins, Penguin(), numPenguins, 1);
	numSpecies++;

	this->numTurtles = getValidIntegerInput("Would you like to buy 1 or 2 Turtles? ", 1, 2);
	fillZoo(turtles, Turtle(), numTurtles, 1);
	numSpecies++;
}

// couldn't get it to work with my setup, it has to do with my 
// animalCapacity for each animal
void Zoo::resizeArray(Animal* animals, int numOfAnimals) {
	//animalCapacity *= 2;
	Animal *tempArr = new Animal[animalCapacity * 2];
	for (int i = 0; i < numOfAnimals; i++) {
		tempArr[i] = animals[i];
	}
	delete[] animals;
	animals = tempArr;
}

// logic to add animals to the zoo
void Zoo::fillZoo(Animal* animals, Animal type, int animalCount, int age) {
	if (animalCount == animalCapacity) {
		resizeArray(animals, animalCount);
	}

	if (dayOfOp == 0) {
		for (int i = 0; i < animalCount; i++) {
			animals[i] = type;
			animals[i].setAge(age);
			numOfCurrentAnimals++;
			bank -= animals->getCost();
		}
	}
	else {
		animals[animalCount - 1] = type;
		animals[animalCount - 1].setAge(age);
		numOfCurrentAnimals++;
		if (age > 0)
			bank -= animals->getCost();
	}
}

double Zoo::feedCosts() {
	double feedCost = 0.00;

	feedCost += tigers->getBaseFoodCost() * numTigers;
	feedCost += penguins->getBaseFoodCost() * numPenguins;
	feedCost += turtles->getBaseFoodCost() * numTurtles;

	cout << "Todays feed cost: $" << feedCost << endl;
	return feedCost;
}

double Zoo::dailyEvent() {
	int randomEvent = RNG(0, 100);
	double bonus = 0.00;
	int whoSick = 0;
	int whoseBaby = 0;
	
	// 0 - 24 an animal gets sick and dies
	if (randomEvent >= 0 && randomEvent < 25) {
		whoSick = RNG(1, numSpecies);
		cout << "Todays Event: A ";
		switch (whoSick)
		{
		case 1: cout << "Tiger got sick today." << endl;
			sick(tigers, numTigers);
			break;
		case 2: cout << "Penguin got sick today." << endl;
			sick(penguins, numPenguins);
			break;
		case 3: cout << "Turtle got sick today." << endl;
			sick(turtles, numTurtles);
			break;
		default: sick(animals, numOfCurrentAnimals);
			break;
		}
	}
	// 25 - 49 national tiger day bonus
	else if (randomEvent >= 25 && randomEvent < 50) {
		bonus = RNG(250, 500) * numTigers;
		cout << "Todays Event: Today is National Tiger Day!\nYour bonus income from tigers was: $" << bonus << endl;
	}
	// 50 - 74 an anmial has a baby(conditions)
	else if (randomEvent >= 50 && randomEvent < 75) {
		whoseBaby = RNG(1, numSpecies);
		switch (whoseBaby)
		{
		case 1: 
			if (baby(tigers, Tiger(), numTigers)) {
				cout << "Todays Event: The Tigers are having a baby!" << endl;
			}
			break;
		case 2: 
			if (baby(penguins, Penguin(), numPenguins)) {
				cout << "Todays Event: The Penguins are having a baby!" << endl;
			}
			break;
		case 3: 
			if (baby(turtles, Turtle(), numTurtles)) {
				cout << "Todays Event: The Turtles are having a baby!" << endl;
			}
			break;
		default: baby(animals, Animal(), numOfCurrentAnimals);
			break;
		}
	}
	// else nothing happened
	else {
		cout << "Todays Event: Nothing interesting happened today." << endl;
	}
	return bonus;
}

void Zoo::sick(Animal* animals, int &numOfAnimal) {
	int sick = 0;
	// copies over the only animal in the array
	if (numOfAnimal == 1) {
		animals[0] = animals[1];
		numOfAnimal--;
		cout << "Unfortunately the last one died!" << endl;
	}
	else {
		sick = RNG(1, numOfAnimal) - 1;
		// removes the animal that "died" and copies the rest of the array over it
		for (int i = sick; i < numOfAnimal; i++) {
			animals[i] = animals[i + 1];
		}
		numOfAnimal--;
		cout << "Unfortunately it ended up dying!" << endl;
	}
	numOfCurrentAnimals--;
}

bool Zoo::baby(Animal* animals, Animal type, int &numOfAnimal) {
	int numBabies = 0;
	// calc number of babies currently
	for (int i = 0; i < numOfAnimal; i++) {
		if (!(animals[i].isAdult())) {
			numBabies++;
		}
	}
	// if they have less than the max number of babies
	// and the number of animals currently, add an animal
	if (numBabies < animals[0].getNumberOfBabies() && numBabies < numOfAnimal) {
		fillZoo(animals, type, ++numOfAnimal, 0);
		return true;
	}
	else {
		dailyEvent();
		return false;
	}
}

double Zoo::calcIncome() {
	double income = 0.00;

	for (int i = 0; i < numTigers; i++) {
		income += tigers[i].getPayoff();
	}
	for (int i = 0; i < numPenguins; i++) {
		income += penguins[i].getPayoff();
	}
	for (int i = 0; i < numTurtles; i++) {
		income += turtles[i].getPayoff();
	}
	return income;
}

void Zoo::buyAnimal() {
	int input = 0;
	int user = 0;

	input = getValidIntegerInput("Would you like to buy an Adult animal?\n1. Yes\n2. No\n", 1, 2);
	if (input == 1) {
		user = getValidIntegerInput("Which would you like to buy?\n1. Tiger\n2. Penguin\n3. Turtle\n", 1, 3);
		switch (user)
		{
		case 1: fillZoo(tigers, Tiger(), ++numTigers, 3);
			break;
		case 2: fillZoo(penguins, Penguin(), ++numPenguins, 3);
			break;
		case 3: fillZoo(turtles, Turtle(), ++numTurtles, 3);
			break;
		default: 
			break;
		}
	}
	else 
		return;
}

void Zoo::ageAnimals() {
	int age = 0;
	for (int i = 0; i < numTigers; i++) {
		age = tigers[i].getAge();
		age++;
		tigers[i].setAge(age);
	}

	for (int i = 0; i < numPenguins; i++) {
		age = penguins[i].getAge();
		age++;
		penguins[i].setAge(age);
	}

	for (int i = 0; i < numTurtles; i++) {
		age = turtles[i].getAge();
		age++;
		turtles[i].setAge(age);
	}
}

void Zoo::begOfDay() {
	dayOfOp++;
	cout << "This is day " << dayOfOp << "!" << endl;
	cout << "This morning there are " << numOfCurrentAnimals << " animals in the zoo!" << endl;
	ageAnimals();
	bank -= feedCosts();
}

bool Zoo::endOfDay() {
	int input = 0;
	
	cout << "There are " << numOfCurrentAnimals << " animals in the zoo at the end of day " << dayOfOp << "!" << endl;
	input = getValidIntegerInput("1. Continue Zoo Tycoon\n2. End Game\nEnter the number of your choice : ", 1, 2);
	if (input == 1)
		return true;
	else
		return false;
}

int Zoo::RNG(int min, int max) {
	return rand() % (max - min + 1) + min;
}
