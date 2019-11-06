/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 8: Searches and Sorts
* LinearSearch.cpp
******************************************************************************/
#include "LinearSearch.hpp"

// idea taken from lecture
int linearSearch(vector<int> haystack, int needle) {
	for (int i = 0; i < haystack.size(); i++) {
		if (haystack[i] == needle) {
			return i;
		}
	}
	return -1;
}