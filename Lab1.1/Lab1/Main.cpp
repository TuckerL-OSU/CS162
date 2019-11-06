#include <iostream>
#include <string>
#include "ReadMatrix.hpp"
#include "Determinant.hpp"
using std::cin;
using std::cout;
using std::endl; 
using std::string;
using std::getline;

// prototypes
int getSizeOfMatrix();


int main() {
	int matrixSize = getSizeOfMatrix();
	double **matrix = new double*[matrixSize];
	readMatrix(matrix, matrixSize);
	
	cout << "has a determinant of: " << determinant(matrix, matrixSize) 
		<< "." << endl;
	// There is an array of arrays
	// loop over main array deleting each sub array
	// then delete the main array
	for (int i = 0; i < matrixSize; i++) {
		//delete array [i]
		delete[]matrix[i];
	}

	//delete matrix
	delete[]matrix;

	return 0;
}

// asks the user to choose the size of they matrix
int getSizeOfMatrix() {
	// used as a flag to keep the loop going until a valid answer is chosen
	int size = -1;
	string input;

	// keep asking them if they want to chose A,a or B,b until they choose one
	do{
		cout << "What size is your matrix?" << endl;
		cout << "A. 2x2\tB. 3x3" << endl;
		// had not previously worked with getline
		// getline http://www.cplusplus.com/doc/tutorial/basic_io/
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

