#include "Queue.h"


Queue::Queue()
{
	front = NULL;
	rear = NULL;
}

Queue::Queue(const Queue& q)
{
	QueueNode *p;
	for (p = q.front; p != NULL; p = p->next)
		enqueue(p->data);
}

Queue::~Queue()
{
	string item;
	while (!isEmpty())
		dequeue(item);
}

bool Queue::isEmpty()
{
	if (front == NULL && rear == NULL)
		return true;
	return false;
}

bool Queue::enqueue(string newItem)
{
	QueueNode* p = new QueueNode;
	if (p == NULL)
		return false;
	p->next = NULL;
	p->data = newItem;
	if (isEmpty())
	{
		front = rear = p;
	}
	else
	{
		rear->next = p;
		rear = p;
	}
	return true;
}

bool Queue::dequeue(string& Item)
{
	if (isEmpty())
		return false;
	Item = front->data;
	if (front == rear)
	{
		delete front;
		front = rear = NULL;
	}
	else
	{
		QueueNode* p = front;
		front = front->next;
		delete p;
	}
	return true;
}

bool Queue::frontValue(string &Item)
{
	if (isEmpty())
		return false;
	Item = front->data;
	return true;
}

bool Queue::PrintQueue()
{
	if (isEmpty())
		return false;
	for (QueueNode* p = front; p != NULL; p = p->next)
		cout << p->data << endl;
	return true;
}

int Queue::size()
{
	int size = 0;
	for (QueueNode* p = front; p != NULL; p = p->next)
		size++;
	return size;
}
int Queue::length()
{
	int length = 0;
	for (QueueNode* p = front; p != NULL; p = p->next)
		length += p->data.size();
	return length;
}