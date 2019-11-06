/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 5: Recursion
* Recursion.cpp
******************************************************************************/
#include "Recursion.hpp"

int main() {
	int input = 0;
	string q1Input = "";
	int q2InputSize = 0;
	int *q2Numbers;
	int q3Input = 0;

	do {
		cout << "1. Reverse String" << endl;
		cout << "2. Sum Integer Array" << endl;
		cout << "3. Triangular Number" << endl;
		cout << "4. Exit" << endl;
		input = getValidIntegerInput("Choose the number of your action: ", 1, 4);

		switch (input) {
		case 1: q1Input = getStringInput();
			cout << reverse(q1Input);
			break;
		case 2: q2InputSize = getValidIntegerInput("How many integers in the array? ", 1, INT_MAX);
			q2Numbers = new int[q2InputSize];
			for (int i = 0; i < q2InputSize; i++) {
				q2Numbers[i] = getValidIntegerInput("Enter an integer for the array: ", 0, INT_MAX);
			}
			cout << "The sum of all the elements in the array is: " << arrayAdder(q2Numbers, q2InputSize) << endl;
			delete[] q2Numbers;
			break;
		case 3: q3Input = getValidIntegerInput("What number do you want to triangulate? ", 1, INT_MAX);
			cout << "The triangle number of " << q3Input << " is: " << triangulate(q3Input) << endl;
			break;
		default: break;
		}
	} while (input != 4);

	return 0;
}

string reverse(string original) {
	if (original.empty()) {
		return "\n";
	}
	return original.at(original.length() - 1) + reverse(original.substr(0, original.length() - 1));
}


int arrayAdder(int* arr, int N) {
	if (N < 1) {
		return 0;
	}
	return arr[N - 1] + arrayAdder(arr, N - 1);
}

int triangulate(int N) {
	if (N < 1) {
		return 0;
	}
	return N + triangulate(N - 1);
}