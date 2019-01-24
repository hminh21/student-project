#ifndef _PRIORITY_QUEUE_h
#define _PRIORITY_QUEUE_h

#include <iostream>
using namespace std;

struct KEY_TYPE
{
	long freq;
	unsigned char data;
	short address;
};
class PRIORITY_QUEUE
{
	KEY_TYPE *key; //array of queue items
	int rear; 
	int maxSize; //maximum size of queue

	void heapify(int i); //adjust heap at position "i"
public:
	PRIORITY_QUEUE(int size); //create queue with 'size' items
	PRIORITY_QUEUE(const PRIORITY_QUEUE& aQueue);
	~PRIORITY_QUEUE(); //destructor

	//operator
	bool isEmpty();
	bool insert(KEY_TYPE item); //push
	bool deleteMin(KEY_TYPE &item); //pop
	void printQueue();
};

#endif