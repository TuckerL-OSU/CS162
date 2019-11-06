#ifndef ROCK_HPP
#define ROCK_HPP
#include "Tool.hpp"

class Rock : public Tool {
public:
	Rock();
	~Rock();

	void setStrength(int);
	int getStrength();

	void setType(char);
	char getType();

	States fight(Tool*);
};

#endif // !ROCK_HPP