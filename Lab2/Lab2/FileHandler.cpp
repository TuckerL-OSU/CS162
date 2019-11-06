/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 2: File I/O
* FileHandler.cpp
******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "FileHandler.hpp"

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::getline;

bool openFile(ifstream &inputFile, string fileName) {
	inputFile.open(fileName);
	return !inputFile;
}

bool openFile(ofstream &outputFile, string fileName) {
	outputFile.open(fileName);
	return !outputFile;
}

void closeFile(ifstream &inputFile) {
	if (inputFile)
		inputFile.close();
}

void closeFile(ofstream &outputFile) {
	if (outputFile)
		outputFile.close();
}

// appends .txt to the file name if the proper file type extension is not used
string getFileName(string message) {
	string fileName;

	cout << message;
	getline(cin, fileName);
	if (fileName.length() > 4 && 
		fileName.substr(fileName.length() - 4) == ".txt") {
		return fileName;
	}
	else {
		return fileName.append(".txt");
	}
}

