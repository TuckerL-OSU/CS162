#include <iostream>
#include <string>
#include "Determinant.hpp"

double determinant(double **matrix, const int SIZE) {
	if (SIZE == 2) {
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}

	else {
		// a(ei - fh)
		return ((matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - 
			(matrix[1][2] * matrix[2][1]))) - 
		// - b(di - fg)	
			(matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - 
			(matrix[1][2] * matrix[2][0]))) + 
		// + c(dh - eg)
			(matrix[0][2] * ((matrix[1][0] * matrix[2][1]) -
			(matrix[1][1] * matrix[2][0]))));
	}
}