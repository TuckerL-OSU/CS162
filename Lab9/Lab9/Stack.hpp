//
//  Stack.hpp
//  Lab9
//
//  Created by Tucker Lavell on 11/23/17.
//

#ifndef Stack_hpp
#define Stack_hpp
#include "Support.hpp"
#include <stack>

using std::stack;

class Stack {
private:
	string original;
	string reverse;
	char *letters;
	stack<char> stackOfLetters;

	void stringToChar();
	void toStack();
	char getReverse();

public:
	Stack(string);
	~Stack();

	void createPalindrome();
	void printPalindrome();

};

#endif /* Stack_hpp */
