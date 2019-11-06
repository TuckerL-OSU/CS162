/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 3: Fantasy Combat Game
* Support.hpp
******************************************************************************/
#include <iostream>
#include <string>
#include <limits>
#include <time.h>
#include <limits.h>
#include <locale>
#include <sstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::numeric_limits;
using std::streamsize;
using std::stringstream;


int getValidInteger(string, int, int);
string getStringInput();
char getCharInput(string);
int RNG(int, int);
bool playAgain();