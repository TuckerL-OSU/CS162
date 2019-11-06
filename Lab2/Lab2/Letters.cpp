/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 2: File I/O
* Letters.cpp
******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Letters.hpp"
#include "FileHandler.hpp"

using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;
using std::to_string;

void count_letters(ifstream &ifs, int* letterCount) {
	ofstream ofs;
	string line;
	int asciiVal;

	while (getline(ifs, line)) {
		for (char &c : line) {
			asciiVal = int(tolower(c));
			// Char a-z => ASCII 97-122
			if (asciiVal >= MIN_ASCII_VAL && asciiVal <= MAX_ASCII_VAL) {
				letterCount[asciiVal - MIN_ASCII_VAL]++;
			}
		}
		output_letters(ofs, letterCount);
		// resets the values in letterCount back to 0
		//https://stackoverflow.com/questions/13308216/how-do-i-clear-a-c-array
		std::fill_n(letterCount, NUMBER_OF_LETTERS, 0);
	}
}

void output_letters(ofstream &ofs, int* letterCount) {
	// retain the number between iterations
	static int paragraphNumber = 1;
	string fileToWrite;

	do {
		fileToWrite = getFileName("Enter the output file name for paragraph "
			+ to_string(paragraphNumber++) + ": ");
	} while (openFile(ofs, fileToWrite));
	for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
		ofs << char(i + MIN_ASCII_VAL) << ":" << letterCount[i] << endl;
	}
	closeFile(ofs);
}