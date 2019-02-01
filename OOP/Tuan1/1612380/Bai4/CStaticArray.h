//File: CStaticArray.h

#ifndef _CSTATICARRAY_H
#define _CSTATICARRAY_H

#include <iostream>
#include <conio.h>

using namespace std;

class CStaticArray
{
	int Arr[100];
	int N;
public:
	void Input();
	void Output();
	void init(int[]);
	int GetSize();
	int Get(int);
	void Set(int, int);
	int Find(int);
	int Max();
	int Min();
	void SortAscending();
	void SortDescending();
};

#endif