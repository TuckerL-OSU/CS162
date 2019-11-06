#ifndef TOOL_HPP
#define TOOL_HPP

enum States {
	WIN = 'w',
	LOSS = 'l',
	DRAW = 'd'
};

class Tool {
protected:
	int strength;
	char type;

public:
	Tool();
	~Tool();

	void setStrength(int);
	virtual int getStrength();

	void setType(char);
	virtual char getType();

	virtual States compareTool(int, int);
	virtual States fight(Tool*);
};

#endif // !TOOL_HPP