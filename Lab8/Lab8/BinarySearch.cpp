/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 8: Searches and Sorts
* BinarySearch.cpp
******************************************************************************/
#include "BinarySearch.hpp"
int binarySearch(vector<int> haystack, int needle, int low, int high);

// http://rosettacode.org/wiki/Binary_search
//	combination of the recursive and iterative
int binarySearch(vector<int> haystack, int needle) {
	// protects low and high from user
	return binarySearch(haystack, needle, 0, haystack.size() - 1);
}

int binarySearch(vector<int> haystack, int needle, int low, int high) {
	int mid = (low + high) / 2;
	if (high < low)
		return -1;
	
	if (haystack[mid] > needle)
		// now search between bottom and 1 less than the middle of the haystack
		return binarySearch(haystack, needle, low, mid - 1);
	else if (haystack[mid] < needle)
		// now search between the middle + 1 and top of the haystack
		return binarySearch(haystack, needle, mid + 1, high);
	else
		// it is the middle of the haystack
		return mid;
}