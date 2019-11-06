#include <iostream>
#include <string>
#include "ReadMatrix.hpp"
#include "Determinant.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

// prototypes
void printMatrix(double**, const int);
double getNumber(int, int);

void readMatrix(double **matrix, const int SIZE) {
	matrix = new double*[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		matrix[i] = new double[SIZE];
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = getNumber(i, j);
		}
	}
	printMatrix(matrix, SIZE);
}

void printMatrix(double **matrix, const int SIZE) {
	cout << "The matrix:" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

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