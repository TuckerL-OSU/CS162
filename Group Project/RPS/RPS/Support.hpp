/**************************************
 * Authors: Christopher Sherman, Sean Cortes, Sergio Ortega-Rojas,
 						Tucker Lavell, Tevin Mantock
 * Date: 11/5/2017
 * Description: A program for implementing a Rock, Paper, Scissors Game. The user
 * chooses their tool, either rock, paper, or scissors, and plays against the
 * computer, which has its own method for picking a tool against the player.
 * This program keeps track of the scores, user v computer, and displays the results
 * to the user.
 * This file contains the function declarations/signatures of the for various
 * functons contained in the Support file
***************************************/
#ifndef SUPPORT_HPP
#define SUPPORT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <limits.h>
#include <locale>
#include <sstream>
#include <cstdlib>

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

#endif