/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 8: Searches and Sorts
* Menu.cpp
* I think I learned how to use another data structure from this lab. I was
	having trouble getting my menu sort option working I was trying to use a
	vector of vectors to store a number related to the file names and the
	actual vectors themselves. I was telling my friend about the problem and
	he suggested looking into map. He said he had learned about maps in school,
	but never had to use them, so I had to learn it myself. Looking into them,
	they seemed like what I needed. Basically combine 2 types of data into
	something that can relate them, using one as a key.
* A map essentially looks like this
					->first			->second
	inputVectors[inputFiles[i]] = vector[i]
	outputVectors[outputFiles[j]] = vector[j]
******************************************************************************/
#include "Menu.hpp"

Menu::Menu() {
	for (int i = 0; i < inputFiles.size(); i++) {
		ifstream ifs;

		openFile(ifs, inputFiles[i]);

		// inserts a new set of data into inputVectors
		inputVectors.insert(pair<string, vector<int>*>(inputFiles[i], new vector<int>));

		// ifs reads into the vector at inputVectors[i]->second
		readFile(ifs, *inputVectors.find(inputFiles[i])->second);
		closeFile(ifs);
	}
	options();
}

Menu::~Menu() {
	for (int i = 0; i < inputVectors.size(); i++) {
		inputVectors.find(inputFiles[i])->second->clear();
	}
	inputVectors.clear();

	for (int i = 0; i < outputVectors.size(); i++) {
		outputVectors.find(outputFiles[i])->second->clear();
	}
	outputVectors.clear();
}


void Menu::options() {
	int input = 0;
	bool sorted = false;

	do {
		cout << "1. Simple Search Inputs\n";
		cout << "2. Bubble Sort\n";
		cout << "3. Binary Search Sorted Files\n";
		cout << "4. Exit\n";
		input = getValidInteger("Choose an action: ", 1, 4);

		int number = 0;
		int index = 0;
		switch (input) {
		case 1: {
			int search = getValidInteger("Enter a value to search: ", INT_MIN, INT_MAX);
			for (int i = 0; i < inputFiles.size(); i++) {
				cout << inputVectors.find(inputFiles[i])->first << ": ";

				index = simpleSearch(*inputVectors.find(inputFiles[i])->second, search);
				if (index == -1) {
					cout << "Search Not Found!" << endl;
				}
				else {
					cout << index << endl;
				}
			}
		}
				break;
		case 2: {
			sort();
			sorted = true;
		}
				break;
		case 3: {
			if (sorted == false) {
				cout << "You must sort the contents of the files before you can do a binary search!" << endl;
			}
			else {
				int search = getValidInteger("Enter a value to binary search: ", INT_MIN, INT_MAX);
				for (int i = 0; i < outputFiles.size(); i++) {
					// file name of vector
					cout << outputVectors.find(outputFiles[i])->first << ": ";

					// searches the vector related to the file 
					index = binSearch(*outputVectors.find(outputFiles[i])->second, search);
					if (index == -1) {
						cout << "Search Not Found!" << endl;
					}
					else {
						cout << index << endl;
					}
				}
			}
		}
		}
	} while (input != 4);
}

int Menu::simpleSearch(vector<int> vecToSearch, int valToSearch) {
	return linearSearch(vecToSearch, valToSearch);
}

void Menu::sort() {
	for (int i = 0; i < inputVectors.size(); i++) {
		ofstream ofs;
		do {
			// clears the current map if it is full
			if (outputVectors.size() == outputFiles.size()) {
				outputVectors.clear();
			}
			outputFiles[i] = getFileName("Enter the output file for " +
				inputVectors.find(inputFiles[i])->first + ": ");
		} while (openFile(ofs, outputFiles[i]));
		
		// inserts a new set of data into outputVectors
		outputVectors.insert(pair<string, vector<int>*>(outputFiles[i], new vector<int>));

		// sorts the outputVector that was created
		*outputVectors.find(outputFiles[i])->second = bubbleSort(*inputVectors.find(inputFiles[i])->second);

		// reads the vector into the related file
		for (int j = 0; j < inputVectors.find(inputFiles[i])->second->size(); j++) {
			ofs << outputVectors.find(outputFiles[i])->second->at(j) << " ";
		}
		closeFile(ofs);
	}

	for (int i = 0; i < outputVectors.size(); i++) {
		ifstream ifs;
		string fileContents = "";

		cout << outputFiles[i] << ": ";
		openFile(ifs, outputFiles[i]);
		while (getline(ifs, fileContents)) {
			cout << fileContents << " ";
		}
		cout << endl;
		closeFile(ifs);
	}
}

int Menu::binSearch(vector<int> vecToSearch, int valToSearch) {
	return binarySearch(vecToSearch, valToSearch);
}

int main() {
	Menu *searchSort = new Menu();
	delete searchSort;

	return 0;
}
