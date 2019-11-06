/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 8: Searches and Sorts
* Menu.hpp
******************************************************************************/
#ifndef MENU_CPP
#define MENU_CPP
#include "BinarySearch.hpp"
#include "LinearSearch.hpp"
#include "Sort.hpp"
#include "File.hpp"
#include "Support.hpp"
#include <map>
#include <array>

using std::map;
using std::pair;
using std::array;

class Menu {
private:
	int simpleSearch(vector<int>, int);
	void sort();
	int binSearch(vector<int>, int);

public:
	Menu();
	~Menu();

	void options();

	map<string, vector<int>*> inputVectors;
	map<string, vector<int>*> outputVectors;
	array<string, 4> inputFiles = { { "original.txt", "early.txt", "middle.txt", "end.txt" } };
	array<string, 4> outputFiles;
};


#endif // !MENU_CPP