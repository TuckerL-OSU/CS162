/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 8: Searches and Sorts
* Sort.cpp
******************************************************************************/
#include "Sort.hpp"
void swap(int*, int*);

// https://en.wikipedia.org/wiki/Bubble_sort
vector<int> bubbleSort(vector<int> original) {
	int sizeOfVec = original.size();
	vector<int> sorted(original);
	bool swapped = true;

	while (swapped) {
		swapped = false;
		for (int i = 1; i < sizeOfVec; i++) {
			if (sorted[i - 1] > sorted[i]) {
				swap(&sorted[i - 1], &sorted[i]);
				swapped = true;
			}
		}
		sizeOfVec--;
	}
	return sorted;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}