/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 2: File I/O
* Letters.hpp
******************************************************************************/

#ifndef LETTERS_HPP
#define LETTERS_HPP

// Constants
const int NUMBER_OF_LETTERS = 26; // length of alphabet
const int MIN_ASCII_VAL = 97; // ascii value of 'a'
const int MAX_ASCII_VAL = 122; // 'z'

void count_letters(std::ifstream &, int*);
void output_letters(std::ofstream &, int*);

#endif