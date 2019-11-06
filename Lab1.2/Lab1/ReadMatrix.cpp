/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 1: Matrix Calculator. ReadMatrix.cpp
******************************************************************************/
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include "ReadMatrix.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::ostringstream;
using std::numeric_limits;
using std::streamsize;

// prototypes
void printMatrix(double**, const int);
double getNumber(int, int);
int getCharCount(double);
int getMaxCharCount(double**, int);

// creates and populates a new 2D array on the heap
void readMatrix(double** matrix, const int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		matrix[i] = new double[SIZE];
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = getNumber(i, j);
		}
	}
	printMatrix(matrix, SIZE);
}

// logic for printing the input matrix
void printMatrix(double **matrix, const int SIZE) {
	cout << "The matrix:" << endl;
	int maxCharCount = getMaxCharCount(matrix, SIZE);
	for (int i = 0; i < SIZE; i++) {
		cout << "| ";
		for (int j = 0; j < SIZE; j++) {
			cout << setw(maxCharCount) << matrix[i][j] << " ";
		}
		cout << "|" << endl;
	}
}

// get the user input for the specific row and coloumn, with validation
double getNumber(int row, int col) {
	double number = 0.0;

	// https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input
	while ((cout << "Enter a number for " << row << "," << col << ": ")
		&& !(cin >> number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid number!\n";
	}

	return number;
}

// converts double into string and returns length of the string (for styling)
// https://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c
int getCharCount(double num) {
	ostringstream strs;
	strs << num;
	string str = strs.str();

	return str.length();
}

// finds the number of digits of the longest input
// could calculate this while inputting into the array
int getMaxCharCount(double** matrix, const int SIZE) {
	int maxChar = 2, tempCharCount;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; j++) {
			if ((tempCharCount = getCharCount(matrix[i][j])) > maxChar) {
				maxChar = tempCharCount;
			}
		}
	}
	return maxChar;
}