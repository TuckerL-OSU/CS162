#include <iostream>
using namespace std;

template <typename T>
T **allocateDynamicArray(int nRows, int nCols)
{
	T **dynamicArray;

	dynamicArray = new T*[nRows];
	for (int i = 0; i < nRows; i++)
		dynamicArray[i] = new T[nCols];

	return dynamicArray;
}

template <typename T>
void freeDynamicArray(T** dArray)
{
	delete[] * dArray;
	delete[] dArray;
}

class Ant {
private:
	int antX;
	int antY;
	int maxSteps;
	int width;
	int height;
	bool **board;

	void clearBoard();
	void printBoard();

public:
	Ant(int, int);
	~Ant();
	void start();
};

void Ant::start() {
	int deltaX = 0;
	int deltaY = 1;
	for (int stepNum = 0; stepNum < this->maxSteps; stepNum++) {
		printBoard();
		if (this->board[antX][antY]) {
			// Turn Left
			if (deltaX == 0) {
				deltaX = deltaY;
				deltaY = 0;
			}
			else {
				deltaY = -deltaX;
				deltaX = 0;
			}
		}
		else {
			// Turn Right
			if (deltaX == 0) {
				deltaX = -deltaY;
				deltaY = 0;
			}
			else {
				deltaY = deltaX;
				deltaX = 0;
			}
		}

		this->board[antX][antY] = !this->board[antX][antY];
		antX += deltaX;
		antY += deltaY;
	}
}

void Ant::clearBoard() {
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			this->board[i][j] = false;
		}
	}
}

void Ant::printBoard() {
	cout << "+";
	for (int i = 0; i < this->width; i++) {
		cout << "-";
	}
	cout << "+" << endl;

	for (int i = 0; i < this->width; i++) {
		cout << "|";
		for (int j = 0; j < this->height; j++) {
			if (antX == i && antY == j) {
				cout << "*";
			}
			else if (this->board[i][j]) {
				cout << "#";
			}
			else {
				cout << " ";
			}
		}
		cout << "|" << endl;
	}

	cout << "+";
	for (int i = 0; i < this->width; i++) {
		cout << "-";
	}
	cout << "+" << endl;
}

Ant::Ant(int width, int height) {
	this->maxSteps = 200;
	this->width = width;
	this->height = height;
	this->antX = width / 2;
	this->antY = height / 2;

	this->board = allocateDynamicArray<bool>(this->width, this->height);
	clearBoard();
}

Ant::~Ant() {
	freeDynamicArray(this->board);
}

int main() {
	Ant ant(70, 70);
	ant.start();
	return 0;
}