#ifndef _LIBRARY_h
#define _LIBRARY_h

#include "ADULT.h"
#include "CHILD.h"
class LIBRARY
{
	vector <MEMBER*> _mem;
public:
	LIBRARY();
	LIBRARY(MEMBER* &m);
	LIBRARY(const LIBRARY& l);
	~LIBRARY();

	//operator
	bool Input();
	bool Output();
	bool Total();
	bool Statistic();
};

#endif