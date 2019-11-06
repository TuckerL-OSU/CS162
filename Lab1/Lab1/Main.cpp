#include <iostream>
#include <string>
#include "ReadMatrix.hpp"
#include "Determinant.hpp"
using std::cin;
using std::cout;
using std::endl; 
using std::string;
using std::getline;

int getSizeOfMatrix();


int main() {
	int matrixSize = getSizeOfMatrix();
	double **matrix = nullptr; 
	readMatrix(*&matrix, matrixSize);
	determinant(*&matrix, matrixSize);
	
	// cout << "has a determinant of: " << ;

	return 0;
}

int getSizeOfMatrix() {
	int size = -1;
	string input;

	do{
		cout << "What size is your matrix?" << endl;
		cout << "A. 2x2\tB. 3x3" << endl;
		//getline http://www.cplusplus.com/doc/tutorial/basic_io/
		getline(cin, input);
		if (input.compare("A") == 0 || input.compare("a") == 0) {
			size = 2;
		}
		else if (input.compare("B") == 0 || input.compare("b") == 0) {
			size = 3;
		}
	} while (size == -1);
		return size;
}

