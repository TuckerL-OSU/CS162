#ifndef PAPER_HPP
#define PAPER_HPP
#include "Tool.hpp"

class Paper : public Tool {
public:
	Paper();
	~Paper();

	void setStrength(int);
	int getStrength();

	void setType(char);
	char getType();

	States fight(Tool*);
};

#endif // !PAPER_HPP

