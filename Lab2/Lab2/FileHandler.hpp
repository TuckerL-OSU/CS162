/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 2: File I/O
* FileHandler.hpp
******************************************************************************/

#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP
#include <fstream>
#include <string>

bool openFile(std::ifstream &, std::string);
bool openFile(std::ofstream &, std::string);
void closeFile(std::ifstream &);
void closeFile(std::ofstream &);
std::string getFileName(std::string);

#endif