#pragma once
#include <iostream>
#include <string>
using namespace std;
class Queue
{
	struct  QueueNode
	{
		string data;
		QueueNode *next;
	};
	QueueNode *front;
	QueueNode *rear;
public:
	Queue(); //default constructor
	Queue(const Queue&); //copy constructor
	~Queue(); //destructor

	// operations
	bool isEmpty();
	bool enqueue(string newItem);
	bool dequeue(string &item);
	bool frontValue(string &item);
	bool PrintQueue();
	int size();
	int length();
};

