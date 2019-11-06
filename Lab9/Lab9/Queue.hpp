//
//  Queue.hpp
//  Lab9
//
//  Created by Tucker Lavell on 11/23/17.
//

#ifndef Queue_hpp
#define Queue_hpp
#include "Support.hpp"
#include <queue>
#include <algorithm>
#include <iterator>

using std::copy;
using std::ostream_iterator;
using std::queue;

class Queue {
private:
	int rounds;
	int chanceToAdd;
	int chanceToDelete;
	queue<int> buffer;
	double avgLength;

	int numToAdd();
	bool addBack();
	bool deleteFront();
	void calcAvgLength(int);

public:
	Queue(int, int, int);
	~Queue();

	void createBuffer();
	void printBufferInfo();
};


#endif /* Queue_hpp */
