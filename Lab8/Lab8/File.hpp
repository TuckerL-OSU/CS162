/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 8: Searches and Sorts
* File.hpp
******************************************************************************/
#ifndef FILE_HPP
#define FILE_HPP
#include "Support.hpp"
#include <fstream>
#include <vector>

using std::ofstream;
using std::ifstream;
using std::vector;

bool openFile(ifstream &, string);
bool openFile(ofstream &, string);
//void readFile(ifstream &, vector<int> &);
vector<int> readFile(ifstream &, vector<int> &);
void writeFile(ofstream &, vector<int>);
void closeFile(ifstream &);
void closeFile(ofstream &);
string getFileName(string);


#endif // !FILE_HPP
