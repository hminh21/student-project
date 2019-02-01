//File: CRand.h

#ifndef _CRAND_H
#define _CRAND_H

#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

class CRand
{
	
public:
	void initSeed();
	int RandInt(int);
	int RandInt(int, int);
	float RandFloat();
};

#endif