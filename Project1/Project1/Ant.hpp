#ifndef ANT_HPP
#define ANT_HPP

enum SlotState {
	WHITE = ' ',
	BLACK = '#'
};

class Ant {
private:
	SlotState **board;
	// Orientation orientation;
	int numRows;
	int numCols;
	int numOfSteps;
	int posX;
	int posY;
	int orientation;

	void move();
	void toggleSlot();
	void turnLeft(int &, int &);
	void turnRight(int &, int &);
	void printBoard();
	void clearBoard();

public:
	Ant(int, int);
	~Ant();
	void start();
	//int getNumRows;
	//int getNumCols;
	//int getNumSteps;
	//int getStartRow;
	//int getStartCol;
};

#endif ANT_HPP
