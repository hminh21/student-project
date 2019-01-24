#include "PRIORITY_QUEUE.h"


PRIORITY_QUEUE::PRIORITY_QUEUE(int size)
{
	if (size <= 0)
		return;

	key = new KEY_TYPE[size];

	if (key == NULL)
	{
		cout << "Khong du bo nho" << endl;
		return;
	}
	rear = -1;

	maxSize = size;	

	for (int i = 0; i < maxSize; i++)
	{
		key[i].freq = 0;
		key[i].data = key[i].address = 256;
	}
}

PRIORITY_QUEUE::PRIORITY_QUEUE(const PRIORITY_QUEUE& aQueue)
{
	maxSize = aQueue.maxSize;
	rear = aQueue.rear;

	key = new KEY_TYPE[maxSize];

	if (key == NULL)
	{
		cout << "Khong du bo nho" << endl;
		return;
	}

	for (int i = 0; i < maxSize; i++)
		key[i] = aQueue.key[i];
}

PRIORITY_QUEUE::~PRIORITY_QUEUE()
{
	if (key != NULL)
		delete key;
	rear = -1;
	maxSize = 0;
}

void PRIORITY_QUEUE::heapify(int i)
{
	KEY_TYPE saved = key[i]; //Save value of key[i]

	while (i < (rear + 1) / 2) // key[i] is not a leaf
	{
		int child = 2 * i + 1; // left child
		if (child < rear)
		{
			if (key[child].freq > key[child + 1].freq || (key[child].freq == key[child + 1].freq && key[child].data > key[child + 1].data))
				child++;
		}
		if (saved.freq < key[child].freq || (saved.freq == key[child].freq && saved.data < key[child].data )) break;

		key[i] = key[child];
		i = child;
	}
	key[i] = saved; //change key[i] to new position
}


bool PRIORITY_QUEUE::isEmpty()
{
	return (rear <= -1);
}

bool PRIORITY_QUEUE::insert(KEY_TYPE item)
{
	if (rear == maxSize)
		return false;
	rear++;
	key[rear] = item; //push

	for (int i = rear / 2; i >= 0; i--)
	{
		heapify(i); //adjust heap
	}
	return true;
}

bool PRIORITY_QUEUE::deleteMin(KEY_TYPE& item)
{

	if (isEmpty() == true)
		return false;
	item = key[0]; //Pop min

	key[0] = key[rear]; //copy value of rear to [0]

	//delete value of rear
	key[rear].data = key[rear].address = 256;
	key[rear].freq = 0;

	rear--; 

	heapify(0); //adjust heap
	return true;
}

void  PRIORITY_QUEUE::printQueue()
{
	for (int i = 0; i <= rear; i++)
		cout << key[i].data << key[i].freq << " ";
	cout << endl;
}
