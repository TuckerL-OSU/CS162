/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 1: Matrix Calculator. Determinant.cpp
******************************************************************************/
#include <iostream>
#include <string>
#include "Determinant.hpp"

// does the math to find the determinant of the input matrix
int determinant(double **matrix, const int SIZE) {
	if (SIZE == 2) {
		// ad - bc
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	} else {
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