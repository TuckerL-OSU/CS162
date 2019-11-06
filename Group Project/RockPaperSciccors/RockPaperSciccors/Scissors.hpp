#ifndef SCISSORS_HPP
#define SCISSORS_HPP
#include "Tool.hpp"

class Scissors : public Tool {
public:
	Scissors();
	~Scissors();

	void setStrength(int);
	int getStrength();

	void setType(char);
	char getType();

	States fight(Tool*);
};

#endif // !SCISSORS_HPP
