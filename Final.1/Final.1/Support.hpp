/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
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
using std::to_string;


int getValidInteger(string, int, int);
string getStringInput(string);
char getCharInput(string);
int RNG(int, int);
void clearScreen();
bool playAgain();