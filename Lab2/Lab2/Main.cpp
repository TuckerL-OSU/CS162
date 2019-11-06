/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 2: File I/O
* Main.cpp
******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "FileHandler.hpp"
#include "Letters.hpp"

using std::ifstream;
using std::ofstream;
using std::string;

// prototypes
void start();

int main() {
	start();	
	return 0;
}

void start() {
	string fileToRead;
	ifstream ifs;
	int letterCount[NUMBER_OF_LETTERS] = { 0 };

	// prompt user to enter a file that exists
	do {
		fileToRead = getFileName("Enter input file name: ");
	} while (openFile(ifs, fileToRead));

	count_letters(ifs, letterCount);
	closeFile(ifs);
}